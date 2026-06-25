#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Flood Fill (DFS)

    Problem:
    - Starting from (sr, sc)
    - Change all connected cells having
      the same initial color to the
      new color.

    Connectivity:
    - Up
    - Right
    - Down
    - Left

--------------------------------------------------

    Approach:

    1. Store initial color.
    2. Start DFS from (sr, sc).
    3. Color current cell.
    4. Visit all 4 neighbors having
       the same initial color.
    5. Continue recursively.

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)
    + O(N * M) recursion stack (worst case)

==================================================
*/

void dfs(int row,
         int col,
         int iniColor,
         vector<vector<int>>& image,
         vector<vector<int>>& ans,
         int delRow[],
         int delCol[],
         int newColor) {

    ans[row][col] = newColor;

    for (int i = 0; i < 4; i++) {

        int r = row + delRow[i];
        int c = col + delCol[i];

        if (r >= 0 &&
            r < image.size() &&
            c >= 0 &&
            c < image[0].size() &&
            image[r][c] == iniColor &&
            ans[r][c] != newColor) {

            dfs(r, c, iniColor,
                image, ans,
                delRow, delCol,
                newColor);
        }
    }
}

vector<vector<int>> floodFill(
    vector<vector<int>>& image,
    int sr,
    int sc,
    int color) {

    vector<vector<int>> ans = image;

    int iniColor = image[sr][sc];

    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    dfs(sr, sc,
        iniColor,
        image,
        ans,
        delRow,
        delCol,
        color);

    return ans;
}

int main() {

    /*
        Image

        1 1 1
        1 1 0
        1 0 1

        sr = 1
        sc = 1
        color = 2

        Output

        2 2 2
        2 2 0
        2 0 1
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(
        n, vector<int>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> image[i][j];
        }
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans =
        floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";

    for (auto& row : ans) {

        for (auto& cell : row) {

            cout << cell << " ";
        }

        cout << "\n";
    }

    return 0;
}