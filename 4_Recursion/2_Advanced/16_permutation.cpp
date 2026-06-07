#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 46 : Permutations
---------------------------------------------------------

Given an array nums of distinct integers,

Return all possible permutations.

---------------------------------------------------------
Method 1 : Using Frequency Array
---------------------------------------------------------

1. Use recursion + backtracking

2. Maintain:
   - current permutation
   - visited/frequency array

3. Try every unused element

---------------------------------------------------------
Method 2 : Using Swapping
---------------------------------------------------------

1. Fix one element at every index

2. Swap current index with all possible
   indices

3. Backtrack by swapping again

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
nums = [1,2,3]

Output:
[1 2 3]
[1 3 2]
[2 1 3]
[2 3 1]
[3 1 2]
[3 2 1]

---------------------------------------------------------
Complexity:
---------------------------------------------------------

Time  : O(N! * N)
Space : O(N)

---------------------------------------------------------
*/



// ----------------------------------------------------
// Method 1 : Frequency Array
// ----------------------------------------------------

void helper1(vector<int>& nums,
             vector<int>& curr,
             vector<int>& freq,
             vector<vector<int>>& ans){

    // Base Case
    if(curr.size() == nums.size()){

        ans.push_back(curr);
        return;
    }

    for(int i = 0 ; i < nums.size() ; i++){

        // If element is not used
        if(!freq[i]){

            curr.push_back(nums[i]);

            freq[i] = 1;

            helper1(nums, curr, freq, ans);

            // Backtracking
            freq[i] = 0;

            curr.pop_back();
        }
    }
}


vector<vector<int>> frequencyMethod(vector<int>& nums){

    vector<vector<int>> ans;

    vector<int> curr;

    vector<int> freq(nums.size(), 0);

    helper1(nums, curr, freq, ans);

    return ans;
}




// ----------------------------------------------------
// Method 2 : Swapping Method
// ----------------------------------------------------

void helper2(vector<int>& nums,
             int ind,
             vector<vector<int>>& ans){

    // Base Case
    if(ind == nums.size()){

        ans.push_back(nums);
        return;
    }

    for(int i = ind ; i < nums.size() ; i++){

        swap(nums[ind], nums[i]);

        helper2(nums, ind + 1, ans);

        // Backtracking
        swap(nums[ind], nums[i]);
    }
}


vector<vector<int>> swappingMethod(vector<int>& nums){

    vector<vector<int>> ans;

    helper2(nums, 0, ans);

    return ans;
}



int main(){

    int n;

    cin >> n;

    vector<int> nums(n);

    for(int i = 0 ; i < n ; i++){
        cin >> nums[i];
    }


    // ------------------------------------------------
    // Frequency Array Method
    // ------------------------------------------------

    cout << "Frequency Array Method:\n";

    vector<vector<int>> ans1 = frequencyMethod(nums);

    for(auto vec : ans1){

        cout << "[ ";

        for(auto it : vec){
            cout << it << " ";
        }

        cout << "]" << endl;
    }


    // ------------------------------------------------
    // Swapping Method
    // ------------------------------------------------

    cout << "\nSwapping Method:\n";

    vector<vector<int>> ans2 = swappingMethod(nums);

    for(auto vec : ans2){

        cout << "[ ";

        for(auto it : vec){
            cout << it << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}