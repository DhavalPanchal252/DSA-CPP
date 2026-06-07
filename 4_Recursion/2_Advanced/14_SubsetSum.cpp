#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
GFG : Subset Sums
---------------------------------------------------------

Given an array arr[],

Return all possible subset sums.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
arr = [1,2,3]

Output:
0 1 2 3 3 4 5 6

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use recursion

2. At every index:
   - Pick the current element
   - Do not pick the current element

3. Store the sum when
   we reach the end

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

arr = [1,2]

                 sum=0
               /       \
          pick 1      not pick
            /             \
       sum=1             sum=0
        /   \             /   \
     +2      no2       +2      no2

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If index reaches array size:

    store current sum

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(2^N)

Because every element has
2 choices:
pick / not pick

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(2^N) + O(N)

O(2^N) -> storing answers
O(N) -> recursion stack

---------------------------------------------------------
*/


void helper(vector<int>& arr, int i, int sum, vector<int>& ans){

    // Base Case
    if(i == arr.size()){

        ans.push_back(sum);
        return;
    }

    // Pick current element
    helper(arr, i + 1, sum + arr[i], ans);

    // Do not pick current element
    helper(arr, i + 1, sum, ans);
}


vector<int> subsetSums(vector<int>& arr){

    vector<int> ans;

    helper(arr, 0, 0, ans);

    sort(ans.begin() , ans .end());
    
    return ans;
}


int main(){

    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector<int> ans = subsetSums(arr);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}