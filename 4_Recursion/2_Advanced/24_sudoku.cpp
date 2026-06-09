#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Sudoku Solver
---------------------------------------------------------

Given a 9 x 9 Sudoku board,
fill the empty cells.

Rules:

1. Each row must contain digits 1-9
2. Each column must contain digits 1-9
3. Each 3x3 subgrid must contain digits 1-9

Empty cells are represented by '.'

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use Backtracking

2. Traverse the board

3. If empty cell found:
      try digits from '1' to '9'

4. Before placing digit:
      check whether it is safe

5. If safe:
      place digit
      recurse for next empty cell

6. If recursion fails:
      backtrack

---------------------------------------------------------
Safety Check:
---------------------------------------------------------

For a digit c:

1. Check row
2. Check column
3. Check 3x3 box

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If all cells are filled:

return true

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Approximately:

O(9^(empty cells))

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(recursion stack)

---------------------------------------------------------
*/



bool isSafe(vector<vector<char>>& board,
            int i,
            int j,
            char c){

    for(int k = 0; k < 9; k++){

        // row check

        if(board[i][k] == c){

            return false;
        }

        // column check

        if(board[k][j] == c){

            return false;
        }

        // 3x3 box check

        if(board[3 * (i / 3) + k / 3]
                [3 * (j / 3) + k % 3] == c){

            return false;
        }
    }

    return true;
}


bool helper(vector<vector<char>>& board){

    for(int i = 0; i < board.size(); i++){

        for(int j = 0; j < board[0].size(); j++){

            // empty cell

            if(board[i][j] == '.'){

                // try digits 1 to 9

                for(char c = '1'; c <= '9'; c++){

                    if(isSafe(board, i, j, c)){

                        board[i][j] = c;

                        if(helper(board)){

                            return true;
                        }

                        // backtrack

                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}


void solveSudoku(vector<vector<char>>& board){

    helper(board);
}



int main(){

    vector<vector<char>> board(9,
                               vector<char>(9));

    // input board

    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 9; j++){

            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << "Solved Sudoku:\n\n";

    for(int i = 0; i < 9; i++){

        for(int j = 0; j < 9; j++){

            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}