#include <bits/stdc++.h>
using namespace std;
// TC : O(n * m), SC : O(1)

int bruteforce(vector<vector<int>> &arr , int n , int m){

    int maxOnes = -1 ;
    int inx = -1 ;

    for(int i = 0 ; i<n ; i++){
        int ones = 0;
        for(int j = 0 ; j<m ; j++){

            ones += arr[i][j];
 
            if(ones>maxOnes){
                maxOnes = ones;
                inx = i;
            }
        }
    }
    return inx;
}

// TC : O(n log m), SC : O(1)

int optimal(vector<vector<int>> &arr , int n , int m){
    int maxOnes = -1 ;
    int inx = -1 ;

    for(int i = 0 ; i<n ; i++){
       
        int low = 0 ; 
        int high = m-1;

        int index = m ;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(arr[i][mid] == 1){
                index = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        int ones = m - index;

        if(ones > maxOnes){
            maxOnes = ones ;
            inx = i ;
        }
    }
    return inx;
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

    // for(auto &i : arr){
    //     for(auto &j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << bruteforce(arr,n,m);
    cout << optimal(arr,n,m);
    return 0;
}