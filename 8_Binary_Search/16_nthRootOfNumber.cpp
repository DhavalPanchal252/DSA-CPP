#include <bits/stdc++.h>
using namespace std;

int bruteForce(int m , int n){// TC : O(m) , SC : O(1)

    for(int i=0 ; i<=m ; i++){

        long long power = pow(i,n);
        if(power>m) break;
        if(power == m) return i;
    }
    return -1;
} 

int optimal(int m , int n){// TC : O(nlogm) , SC : O(1)

    int low = 1;
    int high = m;

    while(low<=high){
        int mid = low + (high - low)/2;

        int ans = 1;
        for(int i=1; i<=n ; i++){
            ans *= mid;
            if(ans> m) break;
        }
        if(ans == m){
            return ans;
        }
        else if(ans<m) low = mid+1;
        else high = mid-1; 
    }
    return -1;
}

int main(){
    
    int m,n; 
    cin >> m >> n;

    cout << bruteForce(m,n);
    // cout << optimal(m,n);
    return 0;
}