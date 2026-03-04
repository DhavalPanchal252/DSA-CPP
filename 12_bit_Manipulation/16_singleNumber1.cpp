#include <bits/stdc++.h>
using namespace std;

/*
========================================
        SINGLE NUMBER PROBLEM
Every element appears twice except one.
Find that single one.
========================================
*/


// --------------------------------------------------
// Brute Force
// TC: O(n^2)
// SC: O(1)
// --------------------------------------------------
int bruteForce(vector<int>& nums) {

    for(int i = 0; i < nums.size(); i++) {

        int count = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[i] == nums[j])
                count++;
        }

        if(count == 1)
            return nums[i];
    }

    return -1;
}



// --------------------------------------------------
// Better Approach (Using HashMap)
// TC: O(n)
// SC: O(n)
// --------------------------------------------------
int better(vector<int>& nums) {

    unordered_map<int,int> freq;

    for(int num : nums)
        freq[num]++;

    for(auto &it : freq) {
        if(it.second == 1)
            return it.first;
    }

    return -1;
}



// --------------------------------------------------
// Optimal Approach (Using XOR)
// TC: O(n)
// SC: O(1)
// --------------------------------------------------
int optimal(vector<int>& nums) {

    int xorr = 0;

    for(int num : nums)
        xorr ^= num;

    return xorr;
}



// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Brute Force: " << bruteForce(nums) << endl;
    cout << "Better (HashMap): " << better(nums) << endl;
    cout << "Optimal (XOR): " << optimal(nums) << endl;

    return 0;
}