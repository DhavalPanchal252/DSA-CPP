#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 90 : Subsets II
---------------------------------------------------------

Given an integer array nums
that may contain duplicates,

Return all possible subsets
without duplicate subsets.

---------------------------------------------------------
Brute Force Approach:
---------------------------------------------------------

1. Generate all subsets

2. Store subsets inside a set
   to automatically remove duplicates

3. Convert set back to vector

---------------------------------------------------------
Optimal Approach:
---------------------------------------------------------

1. Sort the array

2. Generate subsets using recursion

3. Skip duplicate elements
   at the same recursion level

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
nums = [1,2,2]

Output:
[]
[1]
[1 2]
[1 2 2]
[2]
[2 2]

---------------------------------------------------------
Brute Force Complexity:
---------------------------------------------------------

Time  : O(2^N * log(unique subsets))
Space : O(2^N)

---------------------------------------------------------
Optimal Complexity:
---------------------------------------------------------

Time  : O(2^N)
Space : O(2^N)

---------------------------------------------------------
*/


// ----------------------------------------------------
// Brute Force Solution
// ----------------------------------------------------

void helper1(vector<int>& arr,
             int i,
             vector<int>& curr,
             vector<vector<int>>& ans){

    // Base Case
    if(i == arr.size()){

        ans.push_back(curr);
        return;
    }

    // Pick current element
    curr.push_back(arr[i]);

    helper1(arr, i + 1, curr, ans);

    curr.pop_back();

    // Do not pick current element
    helper1(arr, i + 1, curr, ans);
}


vector<vector<int>> bruteForce(vector<int>& nums){

    vector<vector<int>> ans;

    vector<int> curr;

    sort(nums.begin(), nums.end());

    helper1(nums, 0, curr, ans);

    // Remove duplicates using set
    set<vector<int>> s;

    for(auto &vec : ans){
        s.insert(vec);
    }

    ans.clear();

    for(auto &vec : s){
        ans.push_back(vec);
    }

    return ans;
}



// ----------------------------------------------------
// Optimal Solution
// ----------------------------------------------------

void helper2(int ind , vector<int> &arr , vector<int> &curr , vector<vector<int>> &ans){

    ans.push_back(curr);

    for(int i=ind ; i<arr.size() ; i++){

        if(i > ind && arr[i] == arr[i-1]) continue;

        curr.push_back(arr[i]);

        helper2(i+1 , arr , curr , ans);

        curr.pop_back();
    }
}


vector<vector<int>> optimal(vector<int>& nums){

    vector<vector<int>> ans;

    vector<int> curr;

    sort(nums.begin(), nums.end());

    helper2(0, nums, curr, ans);

    return ans;
}



int main(){

    int n;

    cin >> n;

    vector<int> nums(n);

    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }

    cout << "Brute Force Answer:\n";

    vector<vector<int>> ans1 = bruteForce(nums);

    for(auto vec : ans1){

        cout << "[ ";

        for(auto it : vec){
            cout << it << " ";
        }

        cout << "]" << endl;
    }


    cout << "\nOptimal Answer:\n";

    vector<vector<int>> ans2 = optimal(nums);

    for(auto vec : ans2){

        cout << "[ ";

        for(auto it : vec){
            cout << it << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}