#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 79 : Word Search
---------------------------------------------------------

Given an m x n board of characters
and a string word,

Return true if the word exists
in the grid.

The word can be formed using:

1. Adjacent cells
2. Horizontal or vertical movement

A cell cannot be reused
in the same path.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:

3 4

A B C E
S F C S
A D E E

ABCCED

Output:

true

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Traverse every cell

2. If current cell matches
   first character of word:

      start DFS + Backtracking

3. From current cell:
      move in 4 directions

      - Down
      - Up
      - Right
      - Left

4. Mark current cell visited

5. Recursively check next character

6. Backtrack by restoring character

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If ind == word.size()

Entire word found

return true

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(m * n * 4^L)

L = length of word

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(L)

(recursion stack)

---------------------------------------------------------
*/

bool helper(vector<vector<char>>& board,
            string word,
            int i,
            int j,
            int ind){

    // word found

    if(ind == word.size()){

        return true;
    }

    // boundary + mismatch check

    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[ind]){

        return false;
    }

    // store current character

    char temp = board[i][j];

    // mark visited

    board[i][j] = '#';

    // move in 4 directions

    bool found =
        helper(board, word, i+1, j, ind+1) ||
        helper(board, word, i-1, j, ind+1) ||
        helper(board, word, i, j+1, ind+1) ||
        helper(board, word, i, j-1, ind+1);

    // backtrack

    board[i][j] = temp;

    return found;
}


bool exist(vector<vector<char>>& board,
            string word){

    int row = board.size();

    int col = board[0].size();

    // start DFS from every cell

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            if(board[i][j] == word[0]){

                if(helper(board,
                            word,
                            i,
                            j,
                            0)){

                    return true;
                }
            }
        }
    }

    return false;
}



int main(){

    int row, col;

    cin >> row >> col;

    vector<vector<char>> board(
        row,
        vector<char>(col)
    );

    // input board

    for(int i = 0; i < row; i++){

        for(int j = 0; j < col; j++){

            cin >> board[i][j];
        }
    }

    string word;

    cin >> word;

    bool ans = exist(board, word);

    if(ans){

        cout << "true";
    }
    else{

        cout << "false";
    }

    return 0;
}