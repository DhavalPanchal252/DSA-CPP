// same as next greatest element
#include <bits/stdc++.h>
using namespace std;

// TC : O(n*m) , SC : O(m)
vector<int> bruteForce(vector<int> &a1,int n,vector<int> &indices,int m){

    vector<int> ans;// n

    for(auto i : indices){
        int cnt = 0;

        for(int j=i+1 ; j<n ; j++){
            if(a1[i] < a1[j]) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(auto &i : arr1) cin >> i;

    int m;
    cin >> m ;

    vector<int> indices(m);
    for(auto &i : indices) cin >> i;

    vector<int> ans = bruteForce(arr1,n,indices,m);

    for(auto &i : ans) cout << i << " ";

    return 0;
}