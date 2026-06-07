#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 39 : Combination Sum
---------------------------------------------------------

Given an array of distinct integers candidates
and a target integer target,

Return all unique combinations where
chosen numbers sum to target.

You may use the same element
multiple times.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
candidates = [2,3,6,7]
target = 7

Output:
[2 2 3]
[7]

---------------------------------------------------------
Approach:
---------------------------------------------------------

For every element:

1. Include current element
   -> stay on same index
   because reuse is allowed

2. Exclude current element
   -> move to next index

Use recursion + backtracking.

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

For [2,3] target = 5

                    5
                 /     \
              take 2   skip 2
               /          \
              3            5
            ...

---------------------------------------------------------
Base Case:
---------------------------------------------------------

When all elements are processed:

    if(target == 0)
        valid combination found

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Exponential

Approximately:

O(2^target)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(target)

Recursion stack + current combination

---------------------------------------------------------
*/


void helper(vector<int> &arr , vector<int> &curr  , int target , int i , vector<vector<int>> & result){

        if( i == arr.size()){
            if(curr.size() != 0 && target == 0){
                result.push_back(curr);
            }
            return;
        } 

        if(target - arr[i] >= 0){

            curr.push_back(arr[i]);
            helper(arr , curr , target - arr[i] , i  , result);
            curr.pop_back();
        } 


        helper(arr , curr , target , i+1 , result);
    }

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
    vector<vector<int>> result;

    vector<int> curr;
    helper(candidates , curr , target , 0 , result);
    return result;
}


int main(){

    int n;

    cin >> n;

    vector<int> candidates(n);

    for(int i = 0 ; i < n ; i++){
        cin >> candidates[i];
    }

    int target;

    cin >> target;

    vector<vector<int>> ans =
        combinationSum(candidates , target);

    for(auto vec : ans){

        for(auto it : vec){
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}