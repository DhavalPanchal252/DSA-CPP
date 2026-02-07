
#include <bits/stdc++.h>
using namespace std;
// TC:O(n) and SC: O(1)
int niceSubarray( vector<int> &nums , int goal){
    
    if(goal < 0) return 0;
    
    int l=0,sum=0;
    long long cnt=0;
    
    for (int r = 0; r < int(nums.size()); r++) {
        if (nums[r] % 2 == 1) sum++;

        while (sum > goal) {
            if (nums[l] % 2 == 1) sum--;
            l++;
        }

        cnt += r - l + 1; // number of subarrays ending at r
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    
    for(int i =0 ; i<n ; i++){
        cin >> num[i];
    }
    
    int goal; 
    cin >> goal;
    cout << niceSubarray(num , goal) - niceSubarray(num , goal-1) ;
    return 0;
}
