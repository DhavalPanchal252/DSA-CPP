#include <bits/stdc++.h>
using namespace std;
/*
same as above que

Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.*/

int helper(vector<int> &a , int time){
    int boardsPainter  = 0 ;
    int cnt = 1; // painters count
    for(int i=0 ; i < a.size() ; i++){
        if(boardsPainter  + a[i] <= time){
            boardsPainter  += a[i];
        }
        else{
            boardsPainter  = a[i];
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

        int painters  = helper(a,mid);

        if(painters  <= k){
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
