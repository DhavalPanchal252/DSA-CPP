#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){ //TC : O(n^2)

    vector<int> ans;

    for(int i = 0 ; i<n ; i++){
        int flag = 1;

        for(int j = i+1 ; j<n ; j++){

            if(a[i]<=a[j]){
                flag = 0; 
                break;
            }
        }
        if(flag) ans.push_back(a[i]);
    }

    for(auto &i : ans) cout << i <<  " ";
}

void optimal(vector<int> &a , int n){ // TC : O(n)

    int maxi = INT_MIN;
    vector<int> ans;

    for(int i = n-1 ; i>= 0 ; i--){

        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi = a[i];
        } 
    }

    reverse(ans.begin(),ans.end());
    for(auto &i : ans) cout << i <<  " ";
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i ;

    // bruteForce(arr,n);
    optimal(arr,n);
    return 0;
}