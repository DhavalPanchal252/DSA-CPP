#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        SINGLE NUMBER - III
Two elements appear once.
All other elements appear exactly twice.
Find the two unique numbers.
==================================================
*/


// --------------------------------------------------
// 1️ Brute Force
// TC: O(n^2)
// SC: O(1)
// --------------------------------------------------
vector<int> bruteForce(vector<int>& nums) {

    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {

        int count = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[i] == nums[j])
                count++;
        }

        if(count == 1)
            ans.push_back(nums[i]);
    }

    return ans;
}


// --------------------------------------------------
// 2️ Better (Using HashMap)
// TC: O(n)
// SC: O(n)
// --------------------------------------------------
vector<int> better(vector<int>& nums) {

    unordered_map<int,int> freq;

    for(int num : nums)
        freq[num]++;

    vector<int> ans;

    for(auto &it : freq) {
        if(it.second == 1)
            ans.push_back(it.first);
    }

    return ans;
}



// --------------------------------------------------
// 3 Optimal (Bit Manipulation)
// TC: O(n)
// SC: O(1)
// --------------------------------------------------
vector<int> optimal(vector<int>& nums) {

    /*
    Step 1:
        XOR all elements.
        Since duplicates cancel out:
            a ^ a = 0
        We are left with:
            xorr = num1 ^ num2

    Step 2:
        Find rightmost set bit of xorr.
        This bit is different between num1 and num2.

        We use:
            (unsigned int)xorr & (-(unsigned int)xorr)

        Why unsigned?
        Because negating INT_MIN in signed int
        causes undefined behavior.
        Unsigned avoids overflow issues.

    Step 3:
        Divide numbers into 2 groups based on that bit.
        - Group 1 → bit present
        - Group 2 → bit not present

        Duplicates fall into same group and cancel.
        Each group leaves exactly one unique number.
    */

    int xorr = 0;

    for(auto &i : nums)
        xorr ^= i;

    int xorr1 = 0;
    int xorr0 = 0;

    // RIGHTMOST SET BIT (safe version)
    // xorr & (-xorr)
    // or
    // (xor & (xor - 1)) ^ xor
    int check = (unsigned int)xorr & (-(unsigned int)xorr);

    for(auto &i : nums){
        if((check & i) == check)
            xorr1 ^= i;
        else
            xorr0 ^= i;
    }

    return {xorr1, xorr0};
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    vector<int> nums = {1,2,1,3,2,5};

    vector<int> ans1 = bruteForce(nums);
    vector<int> ans2 = better(nums);
    vector<int> ans3 = better2(nums);
    vector<int> ans4 = optimal(nums);

    cout << "Brute Force: ";
    for(auto &i : ans1) cout << i << " ";
    cout << endl;

    cout << "Better (HashMap): ";
    for(auto &i : ans2) cout << i << " ";
    cout << endl;

    cout << "Optimal (Bit Manipulation): ";
    for(auto &i : ans4) cout << i << " ";
    cout << endl;

    return 0;
}