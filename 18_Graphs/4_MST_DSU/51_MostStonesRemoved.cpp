#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Most Stones Removed

        Disjoint Set (DSU)

-------------------------------------------

Idea

Treat every row and every column
as a separate DSU node.

For each stone

(row, col)

connect

row ---- column

Each connected component must
keep one stone.

Answer

Total Stones - Components

Time Complexity : O(N × α(N))

Space Complexity : O(MaxRow + MaxCol)

===========================================
*/

class DisjointSet {

public:

    vector<int> parent, Size;

    DisjointSet(int n) {

        parent.resize(n);
        Size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {

        if (parent[node] == node)
            return node;

        return parent[node] =
            findParent(parent[node]);
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

int removeStones(vector<vector<int>>& stones) {

    int maxRow = 0;
    int maxCol = 0;

    for (auto &stone : stones) {

        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }

    // Row Nodes : 0 ... maxRow
    // Column Nodes : maxRow+1 ...

    DisjointSet ds(maxRow + maxCol + 2);

    unordered_map<int,int> usedNodes;

    // Connect row node with column node

    for (auto &stone : stones) {

        int rowNode = stone[0];
        int colNode = stone[1] + maxRow + 1;

        ds.unionBySize(rowNode, colNode);

        usedNodes[rowNode] = 1;
        usedNodes[colNode] = 1;
    }

    // Count connected components

    int components = 0;

    for (auto &node : usedNodes) {

        if (ds.findParent(node.first) == node.first)
            components++;
    }

    return stones.size() - components;
}

int main() {

    /*
            Stones

            (0,0)
            (0,2)
            (1,1)
            (2,0)
            (2,2)

            Components = 2

            Answer

            5 - 2 = 3
    */

    vector<vector<int>> stones = {

        {0,0},
        {0,2},
        {1,1},
        {2,0},
        {2,2}
    };

    cout << "Maximum Stones Removed = "
         << removeStones(stones)
         << endl;

    return 0;
}