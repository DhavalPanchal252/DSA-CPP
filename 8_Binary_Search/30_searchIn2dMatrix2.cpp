#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order. But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
*/

// TC : O(n * m), SC : O(1)
bool bruteforce(vector<vector<int>> &arr , int n , int m , int target){
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j] == target) return true;
        }
    }
    return false;
}
// TC : O(n * logm), SC : O(1)
bool better(vector<vector<int>> &arr , int n , int m , int target){

    for(int i=0 ; i < n ; i++){

        if(binary_search(arr[i].begin(),arr[i].end(),target)) return true;
        // int low = 0 ; 
        // int high = m-1;

        // while(low<=high){

        //     int mid = low + (high - low)/2;

        //     if(arr[i][mid] == target) return true;
        //     else if(arr[i][mid] < target) low = mid + 1;
        //     else high = mid -1 ;
        // }
    }
    return false;
}

// TC : O(m + n), SC : O(1)

bool optimal(vector<vector<int>> &arr , int n , int m , int target){

    int row = 0 ; 
    int col = m-1;

    while(row < n && col>=0){

        if(arr[row][col] == target) return true;
        else if(arr[row][col] > target) col--;
        else row++;

    }
    return false;
}

int main(){

    int n , m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n,vector<int>(m));

    for(auto &i : arr){
        for(auto &j : i){
            cin >> j;
        }
    }

    int target;
    cin >> target;
    // for(auto &i : arr){
    //     for(auto &j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << bruteforce(arr,n,m,target);
    // cout << better(arr,n,m,target);
    cout << optimal(arr,n,m,target);

    return 0;
}