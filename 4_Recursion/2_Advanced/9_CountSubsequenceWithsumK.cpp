#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Count All Subsequences With Sum K
---------------------------------------------------------

Given an array arr and target sum k,

Count total subsequences whose sum equals k.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
arr = [1, 2, 1]
k = 2

Output:
2

Explanation:
Valid subsequences:
[1, 1]
[2]

---------------------------------------------------------
Approach:
---------------------------------------------------------

For every element:

1. Include the element
2. Exclude the element

Recursively generate all subsequences.

If remaining sum becomes 0
after processing all elements,
count that subsequence.

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

For arr = [1, 2]

                    sum = 2
                   /       \
             take 1      skip 1
              /              \
          sum=1             sum=2
          ...

---------------------------------------------------------
Base Case:
---------------------------------------------------------

When all elements are processed:

    if(sum == 0)
        return 1

    else
        return 0

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(2^n)

Every element has:
- include
- exclude

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

Recursion stack depth.

---------------------------------------------------------
*/


int helper(vector<int> &arr , int i , int sum){

    // Base Case
    if(i == arr.size()){

        return sum == 0;
    }

    // Include + Exclude
    return helper(arr , i + 1 , sum - arr[i]) + helper(arr , i + 1 , sum);
}


int countSubsequenceSum(vector<int>& arr , int k){

    return helper(arr , 0 , k);
}


int main(){

    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int k;

    cin >> k;

    cout << countSubsequenceSum(arr , k);

    return 0;
}