#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbours to the left, right, top, and bottom.
Assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
*/

int maxElement(vector<vector<int>> &mat , int n , int m , int mid){

    int maxi = -1 ; 
    int inx = -1 ; 

    for(int i = 0 ; i < n ; i++){
        if(mat[i][mid]>maxi){
            maxi = mat[i][mid];
            inx = i ; 
        }
    }
    return inx;
}
// TC : O(n+m) and SC : O(1)
vector<int> optimal(vector<vector<int>> &mat , int n , int m){

    int low = 0 ;
    int high = m-1 ;

    while(low <= high){

        int mid = low + (high - low)/2;

        int row = maxElement(mat,n,m,mid);

        int left = mid - 1 >= 0 ? mat[row][mid-1] : -1;
        int right = mid + 1 < m ? mat[row][mid+1] : -1;

        if(left < mat[row][mid] && mat[row][mid] > right){
            return {row,mid};
        }
        else if( left > mat[row][mid]) high = mid - 1;
        else low = mid + 1 ;
    }
    return {-1,-1};
}
int main(){

    int n , m;
    cin >> n >> m;
    
    vector<vector<int>> mat(n,vector<int>(m));

    for(auto &i : mat){
        for(auto &j : i){
            cin >> j;
        }
    }
    // for(auto &i : mat){
    //     for(auto &j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
   
    vector<int> ans = optimal(mat,n,m);

    for(auto &i : ans){
        cout << i << " ";
    }

    return 0;
}