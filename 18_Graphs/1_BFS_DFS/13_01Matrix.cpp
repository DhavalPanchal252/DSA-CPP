#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            01 Matrix (Multi-Source BFS)

    Problem:
    Given a matrix containing only 0s and 1s,
    find the distance of each cell from the
    nearest 0.

--------------------------------------------------

    Approach:

    Instead of running BFS from every 1,
    start BFS from all 0s simultaneously.

    Why?

    Because every cell wants the distance
    to its nearest 0.

    So all 0s become sources.

--------------------------------------------------

    Steps:

    1. Push all 0 cells into queue with
       distance = 0.

    2. Mark them visited.

    3. Run Multi-Source BFS.

    4. When visiting neighbours:
       distance = current distance + 1

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)

==================================================
*/

vector<vector<int>> updateMatrix(
    vector<vector<int>>& mat) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(
        n, vector<int>(m, 0));

    vector<vector<int>> dist(
        n, vector<int>(m, 0));

    queue<pair<pair<int,int>,int>> q;

    // Push all 0's into queue

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (mat[i][j] == 0) {

                q.push({{i, j}, 0});

                vis[i][j] = 1;
            }
        }
    }

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    while (!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        q.pop();

        dist[row][col] = steps;

        for (int k = 0; k < 4; k++) {

            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            if (newRow >= 0 &&
                newRow < n &&
                newCol >= 0 &&
                newCol < m &&
                !vis[newRow][newCol]) {

                vis[newRow][newCol] = 1;

                q.push(
                    {{newRow, newCol},
                     steps + 1});
            }
        }
    }

    return dist;
}

int main() {

    /*
        Matrix

        0 0 0
        0 1 0
        1 1 1

        Distances

        0 0 0
        0 1 0
        1 2 1
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(
        n, vector<int>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans =
        updateMatrix(mat);

    cout << "Distance Matrix:\n";

    for (auto &row : ans) {

        for (auto &cell : row) {

            cout << cell << " ";
        }

        cout << "\n";
    }

    return 0;
}