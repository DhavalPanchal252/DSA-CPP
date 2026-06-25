#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Rotten Oranges

    Cell Values:

    0 -> Empty Cell
    1 -> Fresh Orange
    2 -> Rotten Orange

--------------------------------------------------

    Approach: Multi-Source BFS

    1. Put all rotten oranges into queue.
    2. Count total fresh oranges.
    3. Start BFS simultaneously from all
       rotten oranges.
    4. Every minute:
       - Rotten oranges spread to
         adjacent fresh oranges.
    5. Track maximum time taken.
    6. If some fresh oranges remain
       unreachable, return -1.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)

==================================================
*/

int orangesRotting(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(
        n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    int fresh = 0;
    int rotten = 0;
    int maxTime = 0;

    // Push all rotten oranges
    // Count fresh oranges

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (grid[i][j] == 2) {

                q.push({{i, j}, 0});

                vis[i][j] = 1;
            }

            if (grid[i][j] == 1) {

                fresh++;
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        q.pop();

        maxTime = max(maxTime, time);

        for (int k = 0; k < 4; k++) {

            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            if (newRow >= 0 &&
                newRow < n &&
                newCol >= 0 &&
                newCol < m &&
                !vis[newRow][newCol] &&
                grid[newRow][newCol] == 1) {

                vis[newRow][newCol] = 1;

                rotten++;

                q.push({{newRow, newCol},time + 1});
            }
        }
    }

    if (rotten != fresh)
        return -1;

    return maxTime;
}

int main() {

    /*
        Grid

        2 1 1
        1 1 0
        0 1 1

        Minute 0

        2 1 1
        1 1 0
        0 1 1

        Minute 1

        2 2 1
        2 1 0
        0 1 1

        Minute 2

        2 2 2
        2 2 0
        0 1 1

        Minute 3

        2 2 2
        2 2 0
        0 2 1

        Minute 4

        2 2 2
        2 2 0
        0 2 2

        Answer = 4
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

    cout << "Time Required: "
         << orangesRotting(grid)
         << endl;

    return 0;
}