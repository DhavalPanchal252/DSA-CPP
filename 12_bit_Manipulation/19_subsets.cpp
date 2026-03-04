#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n)
// SC: O(2^n * n)
vector<vector<int>> optimal(vector<int> &arr , int n){

    vector<vector<int>> ans;

    int subsets = 1 << n;   // total subsets = 2^n

    for(int mask = 0 ; mask < subsets ; mask++){

        vector<int> list;

        for(int i = 0 ; i < n ; i++){
            if(mask & (1 << i)){
                list.push_back(arr[i]);
            }
        }

        ans.push_back(list);
    }

    return ans;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    vector<vector<int>> ans = optimal(arr,n);

    for(auto &subset : ans){
        for(auto &num : subset){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}