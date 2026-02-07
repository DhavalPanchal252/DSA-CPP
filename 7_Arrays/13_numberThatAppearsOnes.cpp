#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &arr , int n){ // O(n^2)

    for(int i = 0 ; i<n ; i++){
        int cnt = 0;
        int num = arr[i];

        for(int j = 0 ; j<n ; j++){

            if(num == arr[j]){
                cnt++;
            }
        }

        if(cnt == 1){
            cout << arr[i];
        }
    } 
}

void better(vector<int> &arr , int n){ // TC: O(N) , SC: O(K)  (K = distinct elements)

    unordered_map<int,int> mpp;

    for(int i=0 ; i<n ; i++){
        mpp[arr[i]]++;
    }

    for(int i=0 ; i<n ; i++){
        if(mpp[arr[i]] == 1){
            cout << arr[i] << " ";
        }
    }
}


void optimal(vector<int> &arr , int n){ // TC : O(n) , SC : O(1)
    int xorr = 0;
    for(int i= 0 ; i<n ; i++){
        xorr = xorr^arr[i];
    }

    cout << xorr ;
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i; 
    }

    // bruteForce(arr,n);
    // better(arr , n);
    optimal(arr , n);
    return 0;
}