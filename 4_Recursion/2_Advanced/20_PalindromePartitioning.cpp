#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 131 : Palindrome Partitioning
---------------------------------------------------------

Given a string s,

Partition s such that every substring
of the partition is a palindrome.

Return all possible palindrome
partitionings of s.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:
s = "aab"

Output:
a a b
aa b

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use recursion + backtracking

2. Start partitioning from index = 0

3. Try every possible substring
   starting from current index

4. If substring is palindrome:
      - include it
      - recurse for remaining string
      - backtrack

---------------------------------------------------------
Palindrome Check:
---------------------------------------------------------

Use two pointers:

start -> beginning
end   -> ending

If characters mismatch:
    not palindrome

Else continue inward.

---------------------------------------------------------
Recursive Flow:
---------------------------------------------------------

Example:

s = "aab"

Start:
[]

Try:
["a"]

Then:
["a", "a"]

Then:
["a", "a", "b"]

Valid partition found.

Backtrack and try:
["aa", "b"]

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If index reaches string size:

    valid partition found

Store current partition.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Approximately:

O(2^N * N)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(N)

---------------------------------------------------------
*/


bool isPalindrome(string s, int start, int end){

    while(start <= end){

        if(s[start++] != s[end--]){
            return false;
        }
    }

    return true;
}


void helper(int ind,
            string& s,
            vector<vector<string>>& ans,
            vector<string>& curr){

    // Base Case
    if(ind == s.size()){

        ans.push_back(curr);
        return;
    }

    // Try every possible substring
    for(int i = ind; i < s.size(); i++){

        // Check palindrome
        if(isPalindrome(s, ind, i)){

            // Choose substring
            curr.push_back(s.substr(ind, i - ind + 1));

            // Recurse
            helper(i + 1, s, ans, curr);

            // Backtracking
            curr.pop_back();
        }
    }
}


vector<vector<string>> partition(string s){

    vector<vector<string>> ans;

    vector<string> curr;

    helper(0, s, ans, curr);

    return ans;
}


int main(){

    string s;

    cin >> s;

    vector<vector<string>> ans = partition(s);

    for(auto& vec : ans){

        for(auto& str : vec){
            cout << str << " ";
        }

        cout << endl;
    }

    return 0;
}