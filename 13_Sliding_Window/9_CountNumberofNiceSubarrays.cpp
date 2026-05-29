#include <bits/stdc++.h>
using namespace std;

/*
Count Number of Nice Subarrays

Given an array of integers nums and an integer k,
return the number of subarrays with exactly k odd numbers.
*/


// TC : O(N^2) , SC : O(1)

int helperBruteForce(vector<int> &arr, int n, int k){

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){

        int oddCount = 0;

        for(int j = i ; j < n ; j++){

            if(arr[j] % 2 != 0){
                oddCount++;
            }

            if(oddCount <= k){
                cnt++;
            }
            else{
                break;
            }
        }
    }

    return cnt;
}


int bruteForce(vector<int> &arr, int n, int k){

    return helperBruteForce(arr, n, k)
         - helperBruteForce(arr, n, k - 1);
}



// TC : O(N) , SC : O(1)

int helper(vector<int>& nums, int k, int n){

    if(k < 0) return 0;

    int l = 0;
    int r = 0;

    int cnt = 0;
    int sum = 0;

    while(r < n){

        sum += nums[r] % 2;

        while(sum > k){

            sum -= nums[l] % 2;

            l++;
        }

        cnt += (r - l + 1);

        r++;
    }

    return cnt;
}


int optimal(vector<int>& nums, int n, int k){

    return helper(nums , k , n)
         - helper(nums , k - 1 , n);
}


int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr){
        cin >> i;
    }

    int k;
    cin >> k;

    // cout << bruteForce(arr, n, k)      ;
    cout << optimal(arr, n, k);

    return 0;
}