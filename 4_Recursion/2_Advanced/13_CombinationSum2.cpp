#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 40 : Combination Sum II
---------------------------------------------------------

Given a collection of candidate numbers
(candidates) and a target number (target),

Find all unique combinations where
the candidate numbers sum to target.

Each number may be used ONLY ONCE.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[1 1 6]
[1 2 5]
[1 7]
[2 6]

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Sort the array

2. Use recursion + backtracking

3. For every element:
   - take current element
   - move to next index
     because one element can be used once

4. Skip duplicates to avoid
   repeated combinations

---------------------------------------------------------
Why Sorting?
---------------------------------------------------------

Sorting helps:

1. Skip duplicate elements

Example:
1 1 2 5

If current element is same as previous
at same recursion level:

    continue;

2. Pruning

If arr[i] > target,
further elements will also be larger.

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

target = 8

                 []
          /        |       \
         1         2        5
       /   \
      1     2
     ...

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If target becomes 0:

    valid combination found

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Exponential

Approximately:

O(2^n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

Recursion stack + current combination

---------------------------------------------------------
*/



void helper(vector<int>& arr, int target , int ind , vector<vector<int>> &ans , vector<int> &curr){

    if(target == 0){
        ans.push_back(curr);
        return;
    }

    for(int i = ind ; i<arr.size() ; i++){

        if(i > ind && arr[i] == arr[i-1]) continue;

        if(target - arr[i] < 0 ) break;

        curr.push_back(arr[i]);

        helper(arr , target - arr[i], i+1 , ans , curr);

        curr.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin() , candidates.end());

    vector<vector<int>> ans;

    vector<int> curr;

    helper(candidates , target , 0 , ans , curr);

    return ans;
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

    vector<vector<int>> ans = combinationSum2(candidates , target);

    for(auto vec : ans){

        for(auto it : vec){
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}