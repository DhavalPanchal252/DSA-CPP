#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Number of Enclaves (DFS)

    Cell Values:

    0 -> Sea
    1 -> Land

--------------------------------------------------

    Definition:

    An enclave is a land cell that cannot
    reach the boundary of the grid by
    moving in 4 directions.

--------------------------------------------------

    Key Observation:

    Any land cell connected to the
    boundary is NOT an enclave.

    So:

    1. Start DFS from all boundary land cells.
    2. Mark all reachable land cells.
    3. Count the remaining unvisited land cells.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)
                       + DFS Stack

==================================================
*/

void dfs(int row,
         int col,
         vector<vector<int>>& vis,
         vector<vector<int>>& grid,
         int delRow[],
         int delCol[]) {

    vis[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < 4; i++) {

        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if (newRow >= 0 &&
            newRow < n &&
            newCol >= 0 &&
            newCol < m &&
            !vis[newRow][newCol] &&
            grid[newRow][newCol] == 1) {

            dfs(newRow,
                newCol,
                vis,
                grid,
                delRow,
                delCol);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(
        n, vector<int>(m, 0));

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // First & Last Column

    for (int i = 0; i < n; i++) {

        if (!vis[i][0] &&
            grid[i][0] == 1) {

            dfs(i, 0,
                vis, grid,
                delRow, delCol);
        }

        if (!vis[i][m - 1] &&
            grid[i][m - 1] == 1) {

            dfs(i, m - 1,
                vis, grid,
                delRow, delCol);
        }
    }

    // First & Last Row

    for (int j = 0; j < m; j++) {

        if (!vis[0][j] &&
            grid[0][j] == 1) {

            dfs(0, j,
                vis, grid,
                delRow, delCol);
        }

        if (!vis[n - 1][j] &&
            grid[n - 1][j] == 1) {

            dfs(n - 1, j,
                vis, grid,
                delRow, delCol);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 1 &&
                !vis[i][j]) {

                count++;
            }
        }
    }

    return count;
}

int main() {

    /*
        Grid

        0 0 0 0
        1 0 1 0
        0 1 1 0
        0 0 0 0

        Boundary Land:
        (1,0)

        DFS marks:
        (1,0)

        Remaining Land:

        (1,2)
        (2,1)
        (2,2)

        Answer = 3
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(
        n, vector<int>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> grid[i][j];
        }
    }

    cout << "Number of Enclaves: "
         << numEnclaves(grid)
         << endl;

    return 0;
}