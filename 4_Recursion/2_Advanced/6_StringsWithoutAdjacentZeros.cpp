#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 3211 :
Generate Binary Strings Without Adjacent Zeros
---------------------------------------------------------

Generate all binary strings of length n
such that there are no consecutive 0s.

---------------------------------------------------------
Approach:
---------------------------------------------------------

At every position:

1. Always place '1'

2. Place '0'
   only if previous character is not '0'

Use recursion + backtracking.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(2^n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

---------------------------------------------------------
*/


void solve(int n , string output){

    // Base Case
    if(n == 0){
        cout << output << endl;
        return;
    }

    // Place 1
    solve(n - 1 , output + '1');

    // Place 0 only if previous != 0
    if(output.empty() || output.back() != '0'){
        solve(n - 1 , output + '0');
    }
}


int main(){

    int n;

    cin >> n;

    solve(n , "");

    return 0;
}