#include <bits/stdc++.h>
using namespace std;

// TC :2n  so , O(n) and SC : O(1)
int main() {
    int n; 
    cin >> n;
    
    vector<int> nums(n);
    
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    int k;
    cin >> k;

    int l = 0, zeros = 0, ans = 0;

    for(int r = 0; r < n; r++) {
        if(nums[r] == 0) zeros++;

        while(zeros > k) {
            if(nums[l] == 0) zeros--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
    return 0;
}
