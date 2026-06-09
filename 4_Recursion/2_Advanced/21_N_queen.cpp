#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 51 : N-Queens
---------------------------------------------------------

The n-queens puzzle is the problem of placing
n queens on an n x n chessboard such that:

1. No two queens attack each other.

A queen can attack:
- Horizontally
- Vertically
- Diagonally

Return all distinct solutions.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
n = 4

Output:

.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use recursion + backtracking

2. Place queens column by column

3. For every column:
      try every row

4. Before placing queen:
      check if position is safe

5. If safe:
      - place queen
      - recurse for next column
      - backtrack

---------------------------------------------------------
Safety Check:
---------------------------------------------------------

Before placing queen at (row, col),
check:

1. Upper Left Diagonal
2. Left Side
3. Lower Left Diagonal

Because queens are placed from:
left -> right

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

Column 0:
    try all rows

Column 1:
    try safe rows

Continue recursively.

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If col == n:

    valid arrangement found

Store board in answer.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Approximately:

O(N!)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(N^2)

(board + recursion stack)

---------------------------------------------------------
*/


bool isSafe(int row , int col , int n , vector<string> &board){

    int r = row;
    int c = col;

    // check upper diagonal

    while(c >=0 && r >= 0){
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    r = row;
    c = col;

    // check left

    while(c >= 0){
        if(board[r][c] == 'Q') return false;
        c--;
    }

    r = row;
    c = col;
    // lower diagonal

    while(c >=0 && r < n){
        if(board[r][c] == 'Q') return false;
        r++;
        c--;
    }

    return true;
}

void helper(int col , int n , vector<string> &board , vector<vector<string>> &ans){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0 ; row < n ; row++){

        if(isSafe(row , col , n , board)){

            board[row][col] = 'Q';

            helper(col+1 , n , board , ans);

            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n){

    vector<vector<string>> ans;

    // Empty board
    vector<string> board;

    string curr(n, '.');

    for(int i = 0; i < n; i++){

        board.push_back(curr);
    }

    helper(0, n, board, ans);

    return ans;
}


int main(){

    int n;

    cin >> n;

    vector<vector<string>> ans =
        solveNQueens(n);

    for(auto& board : ans){

        for(auto& row : board){

            cout << row << endl;
        }

        cout << endl;
    }

    return 0;
}