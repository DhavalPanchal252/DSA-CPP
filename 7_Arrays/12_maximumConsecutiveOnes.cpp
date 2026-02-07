#include <bits/stdc++.h>
using namespace std;

int maxConsOnes(vector<int> &arr , int n){ // O(n)

    int cnt = 0;
    int maximum = INT_MIN;

    for(int i=0 ; i<n ; i++){

        if(arr[i]==1){
            cnt++;
            maximum = max(cnt , maximum); 
        }
        else{
            cnt = 0;
        }
    }
    return maximum;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i; 
    }

    cout << maxConsOnes(arr,n);
    return 0;
}