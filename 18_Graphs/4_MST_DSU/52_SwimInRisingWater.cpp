#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Swim in Rising Water

        Disjoint Set (DSU)

-------------------------------------------

Idea

1. Sort all cells by elevation.
2. Add cells one by one.
3. Union with visited neighbours.
4. As soon as source and destination
   become connected, return the
   current elevation.

Time Complexity : O(N² log(N²))

Space Complexity : O(N²)

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

int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();

    DisjointSet ds(n * n);

    // {elevation, {row, col}}

    vector<pair<int, pair<int,int>>> cells;

    for (int row = 0; row < n; row++) {

        for (int col = 0; col < n; col++) {

            cells.push_back(
                {grid[row][col], {row, col}}
            );
        }
    }

    sort(cells.begin(), cells.end());

    vector<vector<int>> vis(n, vector<int>(n, 0));

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    for (auto &cell : cells) {

        int elevation = cell.first;
        int row = cell.second.first;
        int col = cell.second.second;

        vis[row][col] = 1;

        int node = row * n + col;

        // Union with visited neighbours

        for (int k = 0; k < 4; k++) {

            int nr = row + dRow[k];
            int nc = col + dCol[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                vis[nr][nc]) {

                int adjNode = nr * n + nc;

                ds.unionBySize(node, adjNode);
            }
        }

        // Source and Destination connected

        if (ds.findParent(0) ==
            ds.findParent(n * n - 1))
            return elevation;
    }

    return -1;
}

int main() {

    /*
            Grid

            0 2
            1 3

            Answer = 3
    */

    vector<vector<int>> grid = {

        {0,2},
        {1,3}
    };

    cout << "Minimum Time = "
         << swimInWater(grid)
         << endl;

    return 0;
}