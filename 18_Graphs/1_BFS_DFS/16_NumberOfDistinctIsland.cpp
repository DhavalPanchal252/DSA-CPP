#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Number of Distinct Islands

    Idea:

    Two islands are considered same
    if their shapes are identical.

--------------------------------------------------

    Trick:

    Store coordinates relative to
    the first cell of the island.

    Example:

    Island:

    1 1
    1

    Stored As:

    (0,0)
    (0,1)
    (1,0)

--------------------------------------------------

    Time Complexity : O(N * M)

    Space Complexity: O(N * M)

==================================================
*/

void dfs(int row,
         int col,
         vector<vector<int>>& vis,
         vector<vector<char>>& grid,
         vector<pair<int,int>>& shape,
         int baseRow,
         int baseCol,
         int delRow[],
         int delCol[],
         int n,
         int m) {

    vis[row][col] = 1;

    shape.push_back(
        {row - baseRow,
         col - baseCol});

    for(int k = 0; k < 4; k++) {

        int newRow = row + delRow[k];
        int newCol = col + delCol[k];

        if(newRow >= 0 &&
           newRow < n &&
           newCol >= 0 &&
           newCol < m &&
           !vis[newRow][newCol] &&
           grid[newRow][newCol] == 'L') {

            dfs(newRow,newCol,
                vis,grid,
                shape,
                baseRow,baseCol,
                delRow,delCol,
                n,m);
        }
    }
}

int countDistinctIslands(
    vector<vector<char>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(
        n, vector<int>(m,0));

    set<vector<pair<int,int>>> st;

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    for(int i=0;i<n;i++) {

        for(int j=0;j<m;j++) {

            if(!vis[i][j] &&
               grid[i][j] == 'L') {

                vector<pair<int,int>> shape;

                dfs(i,j,
                    vis,grid,
                    shape,
                    i,j,
                    delRow,delCol,
                    n,m);

                st.insert(shape);
            }
        }
    }

    return st.size();
}

int main() {

    vector<vector<char>> grid = {

        {'L','L','W','W','W'},
        {'L','W','W','W','W'},
        {'W','W','W','L','L'},
        {'W','W','W','L','W'}
    };

    cout << "Distinct Islands = "
         << countDistinctIslands(grid);

    return 0;
}