#include <bits/stdc++.h>
using namespace std;

/*
Jump Game II

You are given an array nums where
nums[i] represents the maximum jump length
from index i.

Return the minimum number of jumps required
to reach the last index.

It is guaranteed that the last index is reachable.
*/


// --------------------------------------------------
// Method 1 : BFS Range / Level Traversal
// --------------------------------------------------
/*
Intuition:

[l, r] represents all indices reachable
with the current number of jumps.

Find the farthest index reachable from
all positions in the current range.

Then move to the next range.

TC : O(N)
SC : O(1)
*/
int jumpRange(vector<int>& nums) {

    int l = 0;
    int r = 0;
    int jumps = 0;

    while(r < nums.size() - 1) {

        int farthest = 0;

        for(int i = l; i <= r; i++) {

            farthest = max(farthest, i + nums[i]);
        }

        l = r + 1;
        r = farthest;

        jumps++;
    }

    return jumps;
}


// --------------------------------------------------
// Method 2 : Optimized Greedy
// --------------------------------------------------
/*
Intuition:

currEnd  -> end of current jump range
farthest -> farthest index reachable from
            the current range

Whenever we reach currEnd,
we must make a jump and extend
the range to farthest.

TC : O(N)
SC : O(1)
*/
int jumpGreedy(vector<int>& nums) {

    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for(int i = 0; i < nums.size() - 1; i++) {

        farthest = max(farthest, i + nums[i]);

        // Finished exploring current range
        if(i == currEnd) {

            jumps++;
            currEnd = farthest;
        }
    }

    return jumps;
}


int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &i : nums)
        cin >> i;

    cout << "Range Method  : "
         << jumpRange(nums) << '\n';

    cout << "Greedy Method : "
         << jumpGreedy(nums) << '\n';

    return 0;
}