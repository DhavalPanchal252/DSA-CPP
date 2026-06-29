#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Number of Provinces

        Disjoint Set (DSU)

-------------------------------------------

Each city is initially its own province.

If two cities are directly connected,
merge their sets.

Finally, count the number of
ultimate parents.

Time Complexity : O(N² × α(N))

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

int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    DisjointSet ds(n);

    // Merge connected cities

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (isConnected[i][j] == 1 && i != j)
                ds.unionBySize(i, j);
        }
    }

    // Count provinces

    int provinces = 0;

    for (int i = 0; i < n; i++) {

        if (ds.findParent(i) == i)
            provinces++;
    }

    return provinces;
}

int main() {

    /*
            Graph

            0 ----- 1

            2

        Adjacency Matrix

            1 1 0
            1 1 0
            0 0 1

        Provinces

        {0,1}

        {2}

        Answer = 2
    */

    vector<vector<int>> isConnected = {

        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << "Number of Provinces = "
         << findCircleNum(isConnected)
         << endl;

    return 0;
}