#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Rat In A Maze
---------------------------------------------------------

Given a maze of size n x n where:

1 -> path exists
0 -> blocked cell

A rat starts from:

(0, 0)

and wants to reach:

(n-1, n-1)

The rat can move:

D -> Down
L -> Left
R -> Right
U -> Up

Return all possible paths.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:

1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Output:

DDRDRR
DRDDRR

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use recursion + backtracking

2. Start from (0,0)

3. Try all 4 directions:
      - Down
      - Left
      - Right
      - Up

4. Move only if:
      - inside boundary
      - not visited
      - cell value is 1

5. Mark current cell visited

6. Recurse for next cell

7. Backtrack by unmarking cell

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If rat reaches:

(n-1, n-1)

Store current path.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(4^(n*n))

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n*n)

(visited matrix + recursion stack)

---------------------------------------------------------
*/


void helper(int i, int j, int n , vector<vector<int>> &maze , string curr , vector
	<string> &ans , vector<vector<int>> &track){
	    
    if(i == (n-1) && j == (n-1)) {
        ans.push_back(curr);
        return;
    }
    
    // down
    
    if(i+1 < n && !track[i+1][j] && maze[i+1][j]){
        
        track[i][j] = 1;
        
        helper(i+1 , j , n , maze , curr + 'D', ans , track);
        
        track[i][j] = 0;
    }
    
    
    
    // left
    
    if(j-1 >= 0 && !track[i][j-1] && maze[i][j-1]){
        
        track[i][j] = 1;
        
        helper(i , j-1 , n , maze , curr + 'L' , ans , track);
        
        track[i][j] = 0;
    }
    
    // right
    
    if( j+1 < n  && !track[i][j+1] && maze[i][j+1]){
        
        track[i][j] = 1;
        
        helper(i , j+1 , n , maze , curr + 'R' , ans , track);
        
        track[i][j] = 0;
    }
    
    
    // upword
    if(i-1 >= 0 && !track[i-1][j] && maze[i-1][j]){
        
        track[i][j] = 1;
        
        helper(i-1 , j , n , maze , curr + 'U' , ans , track);
        
        track[i][j] = 0;
    }
    
}
vector<string> ratInMaze(vector<vector<int>> & maze) {
    // code here
    vector<string> ans;
    string curr = "";
    int n = maze.size();
    vector<vector<int>> track(n, vector<int>(n,0));
    
    if(maze[0][0] == 1) helper(0, 0, n, maze, curr, ans, track);
    
    return ans;
}


int main(){

    int n;

    cin >> n;

    vector<vector<int>> maze(
        n,
        vector<int>(n)
    );

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cin >> maze[i][j];
        }
    }

    vector<string> ans = ratInMaze(maze);

    for(auto path : ans){

        cout << path << endl;
    }

    return 0;
}