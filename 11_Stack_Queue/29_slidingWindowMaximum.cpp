#include <bits/stdc++.h>
using namespace std;

// TC : O(n*k) , SC : O(1)
vector<int> bruteForce(vector<int> &arr , int n ,int k){
    vector<int> ans; // we not use any extra space

    for(int i=0 ; i<=n-k ; i++){ // n
        int maxi = INT_MIN;
        for(int j=i ; j<i+k ; j++){   // k 
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

// TC : O(n) , SC : O(k)
vector<int> optimal(vector<int> &arr , int n ,int k){
    vector<int> ans; // we not use any extra space

    deque<int> q; // k

    for(int i=0 ; i < n ; i++){

        while(!q.empty() && q.front() <= i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[i] >= arr[q.back()]){
            q.pop_back();
        }

        q.push_back(i);

        if(!q.empty() && i>=k-1){
            ans.push_back(arr[q.front()]);
        }
    }
    return ans;
}
int main(){
    
    int n;
    cin >> n ;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int k;
    cin >> k;

    // vector<int> ans = bruteForce(arr,n,k);
    vector<int> ans = optimal(arr,n,k);

    for(auto &i : ans) cout << i << " ";
    return 0;
}