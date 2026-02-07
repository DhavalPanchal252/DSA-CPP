#include <bits/stdc++.h>
using namespace std;

// TC : O(n) and SC : O(1)
int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];

    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while(l < r) {
        if(height[l] <= height[r]) {
            if(height[l] >= leftMax)
                leftMax = height[l];
            else
                water += leftMax - height[l];
            l++;
        }
        else {
            if(height[r] >= rightMax)
                rightMax = height[r];
            else
                water += rightMax - height[r];
            r--;
        }
    }

    cout << water;
    return 0;
}
