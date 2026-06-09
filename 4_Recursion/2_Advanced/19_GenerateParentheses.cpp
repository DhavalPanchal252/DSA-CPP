#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 22 : Generate Parentheses
---------------------------------------------------------

Given n pairs of parentheses,

Write a function to generate all
combinations of well-formed parentheses.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
n = 3

Output:
((()))
(()())
(())()
()(())
()()()

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use recursion + backtracking

2. Keep track of:
   - open brackets used
   - close brackets used

3. Rules:
   - open < n
        -> we can place '('

   - close < open
        -> we can place ')'

4. Backtrack after recursion

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

Start:

""

Try:
(
()

etc...

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If current string length becomes 2*n:

    valid answer found

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Catalan Number

Approximately:

O(4^N / sqrt(N))

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(N)

---------------------------------------------------------
*/


void helper(int n,
            string& curr,
            vector<string>& ans,
            int open,
            int close){

    // Base Case
    if(curr.size() == 2 * n){

        ans.push_back(curr);
        return;
    }

    // Place '('
    if(open < n){

        curr.push_back('(');

        helper(n, curr, ans, open + 1, close);

        // Backtracking
        curr.pop_back();
    }

    // Place ')'
    if(close < open){

        curr.push_back(')');

        helper(n, curr, ans, open, close + 1);

        // Backtracking
        curr.pop_back();
    }
}


vector<string> generateParenthesis(int n){

    vector<string> ans;

    string curr = "";

    helper(n, curr, ans, 0, 0);

    return ans;
}


int main(){

    int n;

    cin >> n;

    vector<string> ans = generateParenthesis(n);

    for(auto& str : ans){
        cout << str << endl;
    }

    return 0;
}