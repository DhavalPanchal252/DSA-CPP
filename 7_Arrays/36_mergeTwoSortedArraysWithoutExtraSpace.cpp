#include <bits/stdc++.h>
using namespace std;

void optimal(vector<int> &nums1,vector<int> &nums2,int m , int n){ // TC : O(m+n) and SC : O(1)
    for(int i = (m-n)-1, j = n-1 , k = m-1;  j >= 0 ;k--) 
    {
        if(i>=0 && nums1[i]>=nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
    }
    for(auto &i : nums1) cout << i << " ";
    
}

int main(){
    int m,n;
    
    cin >> m >> n;
    vector<int> nums1(m),nums2(n);

    for(auto &i : nums1) cin >> i;
    for(auto &i : nums2) cin >> i;

    optimal(nums1,nums2,m,n);
    return 0;
}