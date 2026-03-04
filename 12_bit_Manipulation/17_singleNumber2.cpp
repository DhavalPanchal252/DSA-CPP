#include <bits/stdc++.h>
using namespace std;

/*
========================================
        SINGLE NUMBER PROBLEM - 2
Every element appears thice except one.
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
// better 2 (Using bits count)
// TC: O(n*32) ~ O(n)
// SC: O(1)
// --------------------------------------------------
int better2(vector<int>& nums) {

    int ans = 0;

    for(int bit=0 ; bit<32 ; bit++){

        int cnt = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] & (1 << bit)) cnt++;
        }

        // If count % 3 == 1 → that bit belongs to single number
        if(cnt % 3 == 1){
            ans = ans | (1 << bit);
        }
    }
    return ans;
}

// --------------------------------------------------
// better 3 (sorting)

// Since elements appear 3 times,
// compare first and second element of each triplet

// TC: O(n*logn) but worst O(n*32)
// SC: O(1)
// --------------------------------------------------
int better3(vector<int>& nums) {

    sort(nums.begin(),nums.end());

    int n = nums.size();

    for(int i=1 ; i<n ; i++){
        if(nums[i] != nums[i-1]){
            return nums[i-1];
        }
    }
    return nums[n-1];
}

// --------------------------------------------------
// optimal (bucket)
// TC: O(n) 
// SC: O(1)
// --------------------------------------------------

/*
    IDEA:

    We maintain two variables:
    - ones → stores bits which have appeared 1 time (mod 3)
    - twos → stores bits which have appeared 2 times (mod 3)

    For every number:
    Step 1:
        ones = (ones XOR num) AND (~twos)

    Step 2:
        twos = (twos XOR num) AND (~ones)

    Explanation:

    XOR helps toggle bits.
    AND with ~twos ensures bits that already appeared twice
    are not counted again in ones.

    This effectively simulates:
        count of each bit modulo 3

    Bit flow:
        Appears 1st time → goes to ones
        Appears 2nd time → goes to twos
        Appears 3rd time → removed from both

    After processing all elements:
        Only the single number remains in 'ones'
    */
int optimal(vector<int>& nums) {

    int ones = 0;
    int twos = 0;

    for(auto &i : nums){
        ones = (ones ^ i) & (~twos);
        twos = (twos ^ i) & (~ones);
    }
    return ones;
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    vector<int> nums = {5 ,1 ,8 ,5 ,8 ,8 ,5};

    cout << "Brute Force: " << bruteForce(nums) << endl;
    cout << "Better (HashMap): " << better(nums) << endl;
    cout << "better2 (bits): " << better2(nums) << endl;
    cout << "better3 (sorting): " << better3(nums) << endl;
    cout << "optimal (bucket): " << optimal(nums) << endl;

    return 0;
}