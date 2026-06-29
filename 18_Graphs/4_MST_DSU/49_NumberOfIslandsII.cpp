#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Number of Islands II

        Disjoint Set (DSU)

-------------------------------------------

Idea

1. Initially, all cells are water.
2. Convert a cell into land.
3. Assume it forms a new island.
4. Merge it with adjacent land cells.
5. Every successful merge reduces
   the island count by 1.

Time Complexity

O(Q × α(N × M))

Q = Number of operations

Space Complexity

O(N × M)

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

vector<int> numOfIslands(int n, int m,
                         vector<vector<int>>& operators) {

    DisjointSet ds(n * m);

    vector<vector<int>> grid(n, vector<int>(m, 0));

    vector<int> ans;

    int islands = 0;

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    for (auto &op : operators) {

        int row = op[0];
        int col = op[1];

        // Already land

        if (grid[row][col]) {

            ans.push_back(islands);
            continue;
        }

        grid[row][col] = 1;
        islands++;

        int node = row * m + col;

        // Check all 4 neighbours

        for (int k = 0; k < 4; k++) {

            int nr = row + dRow[k];
            int nc = col + dCol[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 1) {

                int adjNode = nr * m + nc;

                if (ds.findParent(node) != ds.findParent(adjNode)) {

                    ds.unionBySize(node, adjNode);
                    islands--;
                }
            }
        }

        ans.push_back(islands);
    }

    return ans;
}

int main() {

    /*
        Grid : 4 x 5

        Operations

        (1,1)
        (0,1)
        (3,3)
        (3,4)

        Island Count

        1
        1
        2
        2
    */

    int n = 4;
    int m = 5;

    vector<vector<int>> operators = {

        {1,1},
        {0,1},
        {3,3},
        {3,4}
    };

    vector<int> ans = numOfIslands(n, m, operators);

    cout << "Number of Islands after each operation\n\n";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}