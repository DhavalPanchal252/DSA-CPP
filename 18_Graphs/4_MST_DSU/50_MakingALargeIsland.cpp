#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Making A Large Island

        Disjoint Set (DSU)

-------------------------------------------

Idea

1. Merge all adjacent land cells.
2. Store the size of each island.
3. For every 0, try converting it to 1.
4. Merge all unique neighbouring islands.
5. Return the maximum possible island size.

Time Complexity : O(N² × α(N²))

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

int largestIsland(vector<vector<int>>& grid) {

    int n = grid.size();

    DisjointSet ds(n * n);

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    int ones = 0;

    // Build connected components of all 1's

    for (int row = 0; row < n; row++) {

        for (int col = 0; col < n; col++) {

            if (grid[row][col] == 0)
                continue;

            ones++;

            int node = row * n + col;

            for (int k = 0; k < 4; k++) {

                int nr = row + dRow[k];
                int nc = col + dCol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    int adjNode = nr * n + nc;

                    ds.unionBySize(node, adjNode);
                }
            }
        }
    }

    // Grid already contains all 1's

    if (ones == n * n)
        return ones;

    int ans = 0;

    // Try converting every 0 into 1

    for (int row = 0; row < n; row++) {

        for (int col = 0; col < n; col++) {

            if (grid[row][col] == 1)
                continue;

            set<int> components;

            for (int k = 0; k < 4; k++) {

                int nr = row + dRow[k];
                int nc = col + dCol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {

                    int adjNode = nr * n + nc;

                    components.insert(ds.findParent(adjNode));
                }
            }

            int islandSize = 1;

            for (int parent : components)
                islandSize += ds.Size[parent];

            ans = max(ans, islandSize);
        }
    }

    return ans;
}

int main() {

    /*
            Grid

            1 0
            0 1

            Flip (0,1)

            1 1
            0 1

            Largest Island = 3
    */

    vector<vector<int>> grid = {

        {1,0},
        {0,1}
    };

    cout << "Largest Island = "
         << largestIsland(grid)
         << endl;

    return 0;
}