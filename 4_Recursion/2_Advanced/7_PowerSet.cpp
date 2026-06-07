#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
GFG : All Possible Strings
---------------------------------------------------------

Given a string s,

Generate all possible non-empty subsequences
of the string.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
s = "abc"

Output:
a ab abc ac b bc c

---------------------------------------------------------
Approach:
---------------------------------------------------------

For every character:

1. Include it
2. Exclude it

This creates all possible subsequences.

Use recursion + backtracking.

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

For "abc":

                    ""
                 /      \
                a        ""
              /   \      /   \
            ab    a     b    ""
           ...

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(2^n * n)

2^n subsequences generated
and each string copy can take O(n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

Recursion stack depth.

---------------------------------------------------------
*/


void helper(string &s , int i ,
            string &current ,
            vector<string> &result){

    // Base Case
    if(i == s.size()){

        // Ignore empty subsequence
        if(current != ""){
            result.push_back(current);
        }

        return;
    }

    // Include current character
    current.push_back(s[i]);

    helper(s , i + 1 , current , result);

    // Backtrack
    current.pop_back();

    // Exclude current character
    helper(s , i + 1 , current , result);
}


vector<string> AllPossibleStrings(string s){

    vector<string> result;

    string current = "";

    helper(s , 0 , current , result);

    // Lexicographical order
    sort(result.begin() , result.end());

    return result;
}


int main(){

    string s;

    cin >> s;

    vector<string> ans = AllPossibleStrings(s);

    for(auto it : ans){
        cout << it << endl;
    }

    return 0;
}