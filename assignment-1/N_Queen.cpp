#include <bits/stdc++.h>
using namespace std;
/*
T(r) = n*T(n-1) + O(n^2)
TC : O( n*n! )
Sc : O(n^2)
*/

vector<vector<string>> final;   // stores all valid board solutions
vector<string> chess_board;     // current board configuration

bool isSafe(int row , int col ,int n){
    
    for (int i = 0; i < row; i++) // check for col
        if (chess_board[i][col] == 'Q') return false;
    
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (chess_board[i][j] == 'Q') return false;
    
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (chess_board[i][j] == 'Q') return false;

    return true;

}

void solve(int row,int n){
    
    if(row == n){ // base case : that measn... all queens are placed
        final.push_back(chess_board);
        return;
    }
    
    for(int col = 0 ; col < n ; col++){
        
        if(isSafe(row,col,n)){
            chess_board[row][col] = 'Q';
            
            solve(row+1,n);
            
            chess_board[row][col] = '-';
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    chess_board = vector<string>(n , string(n,'-'));
    
    solve(0,n);
        
    if (final.empty()) { 
        cout << "[]";
        return 0;
    }

    cout << "[";
    for (int i = 0; i < (int)final.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << "\"" << final[i][j] << "\"";
            if (j != n - 1) cout << ",";
        }
        cout << "]";
        if (i != (int)final.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}
