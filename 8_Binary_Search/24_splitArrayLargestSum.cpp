#include <bits/stdc++.h>
using namespace std;
/*
same as above que

Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.
*/
int helper(vector<int> &a , int possibleSum){
    int sum = 0 ;
    int cnt = 1;
    for(int i=0 ; i < a.size() ; i++){
        if(sum + a[i] <= possibleSum){
            sum += a[i];
        }
        else{
            sum = a[i];
            cnt++;
        }
    }
    return cnt;
}
// TC : O((sum - max)*n)

int bruteForce(vector<int> &a, int k){ 

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);
    for(int i=low ; i<=high ; i++){
        
        if(helper(a,i) == k) return i ;
    }
    return -1;
}

// TC : O(logn(sum - max)*n)

int optimal(vector<int> &a, int k){

    if(k>a.size()) return -1;

    int low = *max_element(a.begin(),a.end()) ;
    int high = accumulate(a.begin(),a.end(),0);

    while(low<=high){
        int mid = low + (high - low)/2; 
        int subarraySum = helper(a,mid);

        if(subarraySum <= k){
            high = mid-1;
        }
        else low = mid+1;
    }
    return low;
}

int main(){

    int n ,k;
    cin >> n >> k;
    
    vector<int> a(n);
    

    for(auto &i : a) cin >> i;

    cout << bruteForce(a,k);
    // cout << optimal(a,k);

    return 0;
}
