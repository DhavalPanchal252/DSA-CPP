#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 139 : Word Break
---------------------------------------------------------

Given a string s and a dictionary wordDict,

Return true if s can be segmented into
a space-separated sequence of one or more
dictionary words.

A dictionary word may be reused
multiple times.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:

leetcode

2

leet
code

Output:

true

Explanation:

"leetcode"
=
"leet" + "code"

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use Recursion + Backtracking

2. Start from index 0

3. Try every possible substring

4. If substring exists in dictionary:
      recursively solve remaining string

5. If any recursive call returns true:
      answer is true

---------------------------------------------------------
Recursive Meaning:
---------------------------------------------------------

helper(ind)

means:

Can substring from index ind
to end be segmented?

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If ind == s.size()

Entire string segmented successfully

return true

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Exponential

O(2^n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

(recursion stack)

---------------------------------------------------------
*/


bool helper(int ind,
            string s,
            unordered_set<string> &st){

    // entire string segmented

    if(ind == s.size()){

        return true;
    }

    string curr = "";

    // try all substrings

    for(int i = ind; i < s.size(); i++){

        curr += s[i];

        // valid dictionary word

        if(st.find(curr) != st.end()){

            if(helper(i + 1,
                      s,
                      st)){

                return true;
            }
        }
    }

    return false;
}


bool wordBreak(string s, vector<string>& wordDict){

    unordered_set<string> st;

    // store dictionary words

    for(auto &i : wordDict){

        st.insert(i);
    }

    return helper(0,
                  s,
                  st);
}


int main(){

    string s;

    cin >> s;

    int n;

    cin >> n;

    vector<string> wordDict(n);

    // input dictionary words

    for(int i = 0; i < n; i++){

        cin >> wordDict[i];
    }

    bool ans =
        wordBreak(s, wordDict);

    if(ans){

        cout << "true";
    }
    else{

        cout << "false";
    }

    return 0;
}