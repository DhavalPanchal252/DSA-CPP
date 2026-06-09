#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 17 : Letter Combinations of a Phone Number
---------------------------------------------------------

Given a string containing digits from 2-9,

Return all possible letter combinations
that the number could represent.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
digits = "23"

Output:
ad ae af
bd be bf
cd ce cf

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Map every digit to its characters

2. Use recursion + backtracking

3. For every character:
   - add character
   - recurse for next digit
   - backtrack

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(4^N * N)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(N)

---------------------------------------------------------
*/


void helper(int ind,
            vector<string>& arr,
            string& curr,
            vector<string>& ans) {

    // Base Case
    if (curr.size() == arr.size()) {

        ans.push_back(curr);
        return;
    }

    for (auto& ch : arr[ind]) {

        curr += ch;

        helper(ind + 1, arr, curr, ans);

        // Backtracking
        curr.pop_back();
    }
}


vector<string> letterCombinations(string digits) {

    map<char, string> mapp;

    mapp['2'] = "abc";
    mapp['3'] = "def";
    mapp['4'] = "ghi";
    mapp['5'] = "jkl";
    mapp['6'] = "mno";
    mapp['7'] = "pqrs";
    mapp['8'] = "tuv";
    mapp['9'] = "wxyz";

    vector<string> arr;

    if (digits.size() == 0)
        return arr;

    for (auto& c : digits) {
        arr.push_back(mapp[c]);
    }

    vector<string> ans;

    string curr;

    helper(0, arr, curr, ans);

    return ans;
}


int main() {

    string digits;

    cin >> digits;

    vector<string> ans = letterCombinations(digits);

    for (auto& str : ans) {
        cout << str << " ";
    }

    return 0;
}