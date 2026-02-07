#include <bits/stdc++.h>
using namespace std;

int bruteForce(int n){// TC : O(n) , SC : O(1)

    int ans = 1;
    for(int i=1 ; i<=n ; i++){
        if(i*i <= n){
            ans = i ; 
        }
        else break;
    }
    return ans;
} 

int optimal(int n){// TC : O(logn) , SC : O(1)

    int low = 1;
    int high = n/2;
    int ans = 1; // if n==1 then while loop fails ans returns ans = 1

    if(n==0) return 0;

    while(low<=high){
        long long mid = low + (high - low)/2;

        if(mid*mid <= n){
            ans =  mid;
            low = mid+1;
            
        }
        else high = mid-1; 
    }
    return ans;
}

int main(){
    
    int n; 
    cin >> n;

    cout << bruteForce(n);
    // cout << optimal(n);
    return 0;
}