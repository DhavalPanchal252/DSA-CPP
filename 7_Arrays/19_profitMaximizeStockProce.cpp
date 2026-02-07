#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){ // O(n^2)

    int maxi = 0;
    for(int i=0 ; i<n ; i++){
        int buy = a[i];
    
        for(int j=i+1 ; j<n ; j++){
        
            int sum = a[j] - buy;
            maxi = max(maxi , sum);
        
        }
    }
    cout << maxi;
}

void optimal(vector<int> &a , int n){ // O(n)
    int min_price = INT_MAX;
    int max_profit = 0;

    for(auto price : a){

        min_price  = min(min_price , price);
        max_profit = max(max_profit , price - min_price);
    }

    cout << max_profit;
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