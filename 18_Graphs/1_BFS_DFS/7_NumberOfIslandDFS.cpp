#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Number of Islands

    Island:
    - Group of connected '1's
    - Connected only in:
        Up, Down, Left, Right

    Approach:
    1. Traverse entire grid.
    2. Whenever an unvisited land
       cell ('1') is found:
       - Increase island count.
       - Run DFS to mark all
         connected land cells.
    3. Return count.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)
    + DFS Recursion Stack

==================================================
*/

void dfs(int row,
         int col,
         vector<vector<int>>& vis,
         vector<vector<char>>& grid,
         int n,
         int m) {

    vis[row][col] = 1;

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {

        int newRow = row + delRow[k];
        int newCol = col + delCol[k];

        if (newRow >= 0 &&
            newRow < n &&
            newCol >= 0 &&
            newCol < m &&
            !vis[newRow][newCol] &&
            grid[newRow][newCol] == '1') {

            dfs(newRow, newCol, vis, grid, n, m);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    int islands = 0;

    vector<vector<int>> vis(n,
                            vector<int>(m, 0));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (!vis[i][j] &&
                grid[i][j] == '1') {

                islands++;

                dfs(i, j, vis, grid, n, m);
            }
        }
    }

    return islands;
}

int main() {

    /*
        Grid

        1 1 0 0 0
        1 1 0 0 0
        0 0 1 0 0
        0 0 0 1 1

        Islands:

        1 1       -> Island 1
        1 1

              1   -> Island 2

                1 1 -> Island 3

        Answer = 3
    */

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(
        n, vector<char>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> grid[i][j];
        }
    }

    cout << "Number of Islands: "
         << numIslands(grid)
         << endl;

    return 0;
}