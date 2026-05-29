#include <bits/stdc++.h>
using namespace std;

/*
Leetcode 992 : Subarrays with K Different Integers

Given an integer array nums and an integer k,
return the number of subarrays with exactly k distinct integers.
*/


// TC : O(N^2) , SC : O(K)

int bruteForce(vector<int> &nums, int n, int k){

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){

        unordered_map<int,int> freq;

        for(int j = i ; j < n ; j++){

            freq[nums[j]]++;

            if(freq.size() == k){
                cnt++;
            }

            else if(freq.size() > k){
                break;
            }
        }
    }

    return cnt;
}



// TC : O(N) , SC : O(K)

int helper(vector<int> &nums , int k){

    if(k < 0) return 0;

    int n = nums.size();

    int l = 0;
    int r = 0;

    int cnt = 0;

    unordered_map<int,int> freq;

    while(r < n){

        freq[nums[r]]++;

        while(freq.size() > k){

            freq[nums[l]]--;

            if(freq[nums[l]] == 0){
                freq.erase(nums[l]);
            }

            l++;
        }

        cnt += (r - l + 1);

        r++;
    }

    return cnt;
}


int optimal(vector<int> &nums , int k){

    return helper(nums , k) - helper(nums , k - 1);
}


int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &i : nums){
        cin >> i;
    }

    int k;
    cin >> k;

    // cout << bruteForce(nums, n, k);
    cout << optimal(nums, k);

    return 0;
}