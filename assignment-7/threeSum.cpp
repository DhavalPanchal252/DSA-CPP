#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2) and SC : O(1)
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end()); // nlogn
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicates for i

        int l = i + 1, r = n - 1;
        while(l < r) {
            long long sum = nums[i] + nums[l] + nums[r];

            if(sum == 0) {
                ans.push_back({nums[i], nums[l], nums[r]});
                l++, r--;

                // skip duplicates for l and r
                while(l < r && nums[l] == nums[l - 1]) l++;
                while(l < r && nums[r] == nums[r + 1]) r--;
            }
            else if(sum < 0) 
                l++;
            else 
                r--;
        }
    }

    if(ans.empty()) {
        cout << "[]";
        return 0;
    }

    for(auto &triplet : ans) {
        cout << "[" << triplet[0] << " " << triplet[1] << " " << triplet[2] << "] ";
    }

    return 0;
}
