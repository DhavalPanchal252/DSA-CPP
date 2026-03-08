#include <bits/stdc++.h>
using namespace std;
/*
==================================================
        FIND UNIQUE BINARY STRING
Given n binary strings each of length n,
return a binary string of length n that
does not exist in the array.
==================================================
*/

// --------------------------------------------------
// 1️⃣ Brute Force
// Generate all binary strings of length n
// and check which one is missing
//
// TC: O(2^n * n)
// SC: O(n)
// --------------------------------------------------
string bruteForce(vector<string>& nums) {

    int n = nums.size();

    unordered_set<string> st(nums.begin(), nums.end());

    for(int i = 0; i < (1 << n); i++){

        string s = "";

        // convert integer → binary string
        for(int j = n - 1; j >= 0; j--){

            if(i & (1 << j))
                s += '1';
            else
                s += '0';
        }

        if(!st.count(s))
            return s;
    }

    return "";
}

// --------------------------------------------------
// 2️⃣ Bitmask Method
// Convert strings → integers
// Track which numbers exist
//
// TC: O(n)
// SC: O(2^n)
// --------------------------------------------------
string bitmaskMethod(vector<string>& nums) {

    unordered_set<int> seen;
    int n = nums.size();

    for(auto &i : nums){
        int val = stoi(i,nullptr,2);
        seen.insert(val);
    }

    for(int i=0 ; i< (1 << n) ; i++){
        if(!seen.count(i)){
            bitset<16> b(i); // converts int to binary bits

            string ans = b.to_string(); // binary bits to strings

            return ans.substr(16 - n);
        }
    }
    return "";
}

// --------------------------------------------------
// 3️⃣ Optimal Solution (Cantor Diagonal Trick)
//
// TC: O(n)
// SC: O(1)
//
// Idea:
// Flip the diagonal element of each string
// --------------------------------------------------
string optimal(vector<string>& nums) {

    int n = nums.size();

    string ans = "";

    for(int i = 0; i < n; i++){

        /*
        Flip the diagonal bit

        If nums[i][i] = '0' → put '1'
        If nums[i][i] = '1' → put '0'
        */

        if(nums[i][i] == '0')
            ans += '1';
        else
            ans += '0';
    }

    return ans;
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    vector<string> nums = {"01","10"};

    cout << "Brute Force Result: "
         << bruteForce(nums) << endl;

    cout << "Bitmask Result: "
         << bitmaskMethod(nums) << endl;

    cout << "Optimal Result: "
         << optimal(nums) << endl;

    return 0;
}