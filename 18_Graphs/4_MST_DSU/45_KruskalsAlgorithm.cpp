#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Kruskal's Algorithm

-------------------------------------------

Minimum Spanning Tree (MST)

Greedy Approach

1. Sort all edges by weight.
2. Pick the smallest edge.
3. If it doesn't form a cycle,
   include it in MST.
4. Repeat until (V-1) edges are chosen.

Cycle Detection

Disjoint Set (Union-Find)

Time Complexity

Sorting  : O(E log E)

DSU      : O(E × α(V))

Overall  : O(E log E)

Space Complexity

O(V)

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

int kruskalsMST(int V, vector<vector<int>>& edges) {

    // {weight, {u, v}}

    vector<pair<int, pair<int, int>>> graph;

    for (auto &e : edges)
        graph.push_back({e[2], {e[0], e[1]}});

    sort(graph.begin(), graph.end());

    DisjointSet ds(V);

    int mstWeight = 0;

    vector<pair<int,int>> mstEdges;

    for (auto &edge : graph) {

        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (ds.findParent(u) != ds.findParent(v)) {

            mstWeight += wt;
            mstEdges.push_back({u, v});

            ds.unionBySize(u, v);
        }
    }

    cout << "Edges in MST\n";

    for (auto &e : mstEdges)
        cout << e.first << " - " << e.second << endl;

    return mstWeight;
}

int main() {

    /*
            Graph

                2
            0-------1
            | \     |
           6|  \3   |8
            |   \   |
            2----7--3

        MST

        0-1 (2)
        0-3 (3)
        0-2 (6)

        Weight = 11
    */

    int V = 4;

    vector<vector<int>> edges = {

        {0,1,2},
        {0,2,6},
        {0,3,3},
        {1,3,8},
        {2,3,7}
    };

    int ans = kruskalsMST(V, edges);

    cout << "\nMST Weight = " << ans << endl;

    return 0;
}