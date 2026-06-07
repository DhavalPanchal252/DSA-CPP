#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr , int i , vector<int> &ans ,  int target , int sum){

    if(i == arr.size()){
        if(sum == target){

            for(auto & i : ans) cout << i << " ";
            cout << endl;
        }
        return;
    }

    ans.push_back(arr[i]);

    helper(arr , i+1 , ans , target , sum + arr[i]);

    ans.pop_back();

    helper(arr , i+1 , ans , target , sum);
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