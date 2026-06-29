#include <bits/stdc++.h>
using namespace std;

/*
===========================================
    Number of Operations to Make
        Network Connected

        Disjoint Set (DSU)

-------------------------------------------

Idea

1. Merge all connected computers.
2. Count extra edges.
3. Count connected components.
4. Need (components - 1) cables.

If extra edges are enough,
return (components - 1),
otherwise return -1.

Time Complexity : O((N + E) × α(N))

Space Complexity : O(N)

===========================================
*/

class DisjointSet {

    vector<int> parent, Size;

public:

    DisjointSet(int n) {

        parent.resize(n);
        Size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {

        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (Size[pu] < Size[pv]) {

            parent[pu] = pv;
            Size[pv] += Size[pu];
        }
        else {

            parent[pv] = pu;
            Size[pu] += Size[pv];
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {

    if (connections.size() < n - 1)
        return -1;

    DisjointSet ds(n);

    int extraEdges = 0;

    for (auto &edge : connections) {

        int u = edge[0];
        int v = edge[1];

        if (ds.findParent(u) == ds.findParent(v))
            extraEdges++;
        else
            ds.unionBySize(u, v);
    }

    int components = 0;

    for (int i = 0; i < n; i++) {

        if (ds.findParent(i) == i)
            components++;
    }

    int requiredEdges = components - 1;

    if (extraEdges >= requiredEdges)
        return requiredEdges;

    return -1;
}

int main() {

    /*
            Computers

            0 ----- 1
            |     /
            |    /
            2

            3 ----- 4

            Connections

            {0,1}
            {0,2}
            {1,2}   <- Extra Edge
            {3,4}

            Components

            {0,1,2}

            {3,4}

            Components = 2

            Required Edges = 1

            Extra Edges = 1

            Answer = 1
    */

    int n = 5;

    vector<vector<int>> connections = {

        {0,1},
        {0,2},
        {1,2},
        {3,4}
    };

    cout << "Minimum Operations = "
         << makeConnected(n, connections)
         << endl;

    return 0;
}