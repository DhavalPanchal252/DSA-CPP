#include <bits/stdc++.h>
using namespace std;

/*
Jump Game

You are given an integer array nums where
nums[i] represents the maximum jump length
from index i.

Return true if you can reach the last index,
otherwise return false.
*/


/*
TC : O(N)
SC : O(1)
*/
bool canJump(vector<int>& nums) {

    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++) {

        // Current index is unreachable
        if(i > maxReach)
            return false;

        // Update the farthest reachable index
        maxReach = max(maxReach, i + nums[i]);

        // Already able to reach the last index
        if(maxReach >= nums.size() - 1)
            return true;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &i : nums)
        cin >> i;

    cout << (canJump(nums) ? "true" : "false");

    return 0;
}