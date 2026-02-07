#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){  // O(n^3)
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){ // j starts from i
            int sum = 0;

            for(int k = i; k <= j; k++){
                sum += a[k];
            }

            maxi = max(maxi, sum);
        }
    }

    cout << maxi;
}

void better(vector<int> &a , int n){  // O(n^2)
    int maxi =INT_MIN;
    for(int i=0 ; i<n ; i++){
        int sum = 0; 
        for(int j=i ; j<n ; j++){
            sum+= a[j];
            maxi = max(sum , maxi); 
        }
    }
    cout << maxi;
}

// Kadan's algo
void optimal(vector<int> &a , int n){  // O(n)
    int maxi =INT_MIN;
    
    int sum = 0;

    for(int i=0 ; i<n ; i++){
        sum+=a[i];

        maxi = max(maxi,sum);

        if(sum<0){
            sum=0;
        }
    }
    cout << maxi;
}

int main(){
          
    int n ; 
    cin >> n;
    
    vector<int> arr(n);

    for(auto &i : arr){
        cin >> i ;
    }

    // bruteForce(arr , n);
    // better(arr , n);
    optimal(arr , n);
    return 0;
}