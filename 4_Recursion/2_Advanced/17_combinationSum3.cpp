#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 216 : Combination Sum III
---------------------------------------------------------

Find all valid combinations of k numbers
that sum up to n such that:

1. Only numbers 1 to 9 are used
2. Each number is used at most once

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
k = 3
n = 7

Output:
[1 2 4]

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Generate numbers from 1 to 9

2. Use recursion + backtracking

3. At every index:
   - Pick current number
   - Do not pick current number

4. Store combination when:
   - size becomes k
   - sum becomes 0

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(2^9)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(k)

---------------------------------------------------------
*/


void helper(vector<int>& arr,
            int k,
            int n,
            int i,
            vector<int>& curr,
            vector<vector<int>>& ans){

    // Valid combination found
    if(curr.size() == k && n == 0){

        ans.push_back(curr);
        return;
    }

    // Base Case
    if(i >= arr.size() || n < 0 || curr.size() > k){
        return;
    }

    // Pick current element
    curr.push_back(arr[i]);

    helper(arr, k, n - arr[i], i + 1, curr, ans);

    curr.pop_back();

    // Do not pick current element
    helper(arr, k, n, i + 1, curr, ans);
}


vector<vector<int>> combinationSum3(int k, int n){

    vector<vector<int>> ans;

    vector<int> curr;

    vector<int> arr;

    // Store numbers from 1 to 9
    for(int i = 1 ; i <= 9 ; i++){
        arr.push_back(i);
    }

    helper(arr, k, n, 0, curr, ans);

    return ans;
}


int main(){

    int k, n;

    cin >> k >> n;

    vector<vector<int>> ans = combinationSum3(k, n);

    for(auto vec : ans){

        cout << "[ ";

        for(auto it : vec){
            cout << it << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}