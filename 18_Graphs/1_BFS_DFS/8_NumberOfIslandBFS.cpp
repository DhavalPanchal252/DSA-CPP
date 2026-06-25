#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Number of Islands (BFS)

    Island:
    - Group of connected '1's
    - Connected only in:
        Up, Down, Left, Right

    Approach:
    1. Traverse the entire grid.
    2. When an unvisited land cell ('1')
       is found:
       - Increment island count.
       - Run BFS from that cell.
    3. BFS visits all connected land cells.
    4. Repeat until all cells are processed.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)

==================================================
*/

void bfs(int row,
         int col,
         vector<vector<int>>& vis,
         vector<vector<char>>& grid,
         int n,
         int m) {

    vis[row][col] = 1;

    queue<pair<int, int>> q;
    q.push({row, col});

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};

    while (!q.empty()) {

        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if (newRow >= 0 &&
                newRow < n &&
                newCol >= 0 &&
                newCol < m &&
                !vis[newRow][newCol] &&
                grid[newRow][newCol] == '1') {

                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
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

                bfs(i, j, vis, grid, n, m);
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
        { (0,0),(0,1),(1,0),(1,1) }

        { (2,2) }

        { (3,3),(3,4) }

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