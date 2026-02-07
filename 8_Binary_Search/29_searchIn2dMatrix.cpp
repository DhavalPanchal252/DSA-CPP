#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
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

// TC : O(log(m*n)), SC : O(1)

bool optimal1(vector<vector<int>> &arr , int n , int m , int target){

    int low = 0;
    int high = n*m-1 ;

    while(low <= high){

        int mid = low + (high - low)/2;

        int row = mid/m;
        int col = mid%2;

        if(arr[row][col] == target) return true;
        else if(arr[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;

}

// TC : O(log(m*n)), SC : O(1)

bool optimal2(vector<vector<int>> &arr , int n , int m , int target){

    int low = 0 ;
    int high = n-1 ;

    while(low <= high){

        int mid = low + (high - low)/2;

        if(arr[mid][0] <= target && target <= arr[mid][m-1]){
            
            return binary_search(arr[mid].begin(),arr[mid].end(),target);
        }
        else if(arr[mid][0] < target) low = mid + 1;
        else high = mid - 1;
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
    // cout << optimal1(arr,n,m,target);
    cout << optimal2(arr,n,m,target);

    return 0;
}