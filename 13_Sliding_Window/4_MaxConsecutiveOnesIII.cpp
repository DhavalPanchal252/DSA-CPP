#include <bits/stdc++.h>
using namespace std;
/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

*/


// TC : O(N^2) , SC : O(1)
int bruteForce(vector<int> &arr, int n , int k){

    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){

        int zeroes = 0;

        for(int j = i ; j < n ; j++){

            if(arr[j] == 0) zeroes++;

            if(zeroes <= k){
                maxLen = max(maxLen , j - i + 1);
            }
        }
    }

    return maxLen;
}

// TC : O(N) , SC : O(1)
int optimal(vector<int> &arr , int n , int k){

    int l = 0;
    int r = 0;
    int maxLen = 0;
    int zeroes = 0 ;

    while(r < n){

        if(arr[r] == 0) zeroes++;

        while(zeroes > k){
            if(arr[l] == 0) zeroes--;
            l++;
        }

        if(zeroes <= k){
            maxLen = max(maxLen , r - l + 1);
        }
        r++;
    }

    return maxLen;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int k;
    cin >> k;

    // cout << bruteForce(arr, n, k);
    cout << optimal(arr, n, k);

    return 0;
}