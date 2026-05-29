#include <bits/stdc++.h>
using namespace std;

// Longest subarray having sum of elements atmost K (<= k)

// TC : O(N^2) , SC : O(1)
int bruteForce(vector<int> &arr, int n , int k){

    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){

        int sum = 0;

        for(int j = i ; j < n ; j++){

            sum += arr[j];

            if(sum <= k){
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
    int sum = 0 ;

    while(r < n){

        sum += arr[r];

        while(sum > k){
            sum -= arr[l];
            l++;
        }

        if(sum <= k){
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