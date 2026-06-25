#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Surrounded Regions (DFS)

    Problem:

    Given a board containing 'X' and 'O',

    Capture all regions surrounded by 'X'.

--------------------------------------------------

    Key Observation:

    Any 'O' connected to the boundary
    can NEVER be surrounded.

    So:

    1. Start DFS from all boundary 'O's.
    2. Mark them as safe (visited).
    3. Traverse the entire board.
    4. Any unvisited 'O' is surrounded.
       Convert it to 'X'.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)
                       + DFS Stack

==================================================
*/

void dfs(int row,
         int col,
         vector<vector<int>>& vis,
         vector<vector<char>>& board,
         int delRow[],
         int delCol[]) {

    vis[row][col] = 1;

    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < 4; i++) {

        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if (newRow >= 0 &&
            newRow < n &&
            newCol >= 0 &&
            newCol < m &&
            !vis[newRow][newCol] &&
            board[newRow][newCol] == 'O') {

            dfs(newRow,
                newCol,
                vis,
                board,
                delRow,
                delCol);
        }
    }
}

void solve(vector<vector<char>>& board) {

    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(
        n, vector<int>(m, 0));

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    // First and Last Column

    for (int i = 0; i < n; i++) {

        if (!vis[i][0] &&
            board[i][0] == 'O') {

            dfs(i, 0,
                vis, board,
                delRow, delCol);
        }

        if (!vis[i][m - 1] &&
            board[i][m - 1] == 'O') {

            dfs(i, m - 1,
                vis, board,
                delRow, delCol);
        }
    }

    // First and Last Row

    for (int j = 0; j < m; j++) {

        if (!vis[0][j] &&
            board[0][j] == 'O') {

            dfs(0, j,
                vis, board,
                delRow, delCol);
        }

        if (!vis[n - 1][j] &&
            board[n - 1][j] == 'O') {

            dfs(n - 1, j,
                vis, board,
                delRow, delCol);
        }
    }

    // Convert surrounded O -> X

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (board[i][j] == 'O' &&
                !vis[i][j]) {

                board[i][j] = 'X';
            }
        }
    }
}

int main() {

    /*
        Board

        X X X X
        X O O X
        X X O X
        X O X X

        Boundary O:
        (3,1)

        Safe Region:
        X O X X

        Surrounded Region:
        O O
          O

        Output:

        X X X X
        X X X X
        X X X X
        X O X X
    */

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(
        n, vector<char>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> board[i][j];
        }
    }

    solve(board);

    cout << "Updated Board:\n";

    for (auto& row : board) {

        for (auto& cell : row) {

            cout << cell << " ";
        }

        cout << "\n";
    }

    return 0;
}