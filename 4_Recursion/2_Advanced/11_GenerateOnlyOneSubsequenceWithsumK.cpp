#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr , int i , vector<int> &ans ,  int target , int sum){

    if(i == arr.size()){
        if(sum == target){

            for(auto & i : ans) cout << i << " ";
            cout << endl;

            return true;
        }
        else return false;
    }

    ans.push_back(arr[i]);

    if(helper(arr , i+1 , ans , target , sum + arr[i]) == true) return true;

    ans.pop_back();

    if(helper(arr , i+1 , ans , target , sum) == true) return true;

    return false;
}

void generateSubsequenceSum(vector<int> &arr , int k){

    vector<int> ans;
    
    helper(arr , 0 , ans , k , 0);
}

int main(){

    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int k;

    cin >> k;

    generateSubsequenceSum(arr , k);


    return 0;
}