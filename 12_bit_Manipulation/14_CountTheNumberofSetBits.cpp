#include <bits/stdc++.h>
using namespace std;

// TC : O(logn) , SC : O(1)
int bruteForce(int n){
    int cnt = 0;

    while(n){
        if(n%2 == 1) cnt++;

        n = n/2;
    }
    return cnt;
}

// TC : O(logn) , SC : O(1)
int optimal1(int n){
    int cnt = 0;

    while(n){
 
        cnt += (n&1);
        n = n >> 1;
    }
    return cnt;
}
// Brian Kernighan’s Algorithm

// TC : O(k) k-> no of set bits , SC : O(1)
int optimal2(int n){
    int cnt = 0;

    while(n){
        
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

// TC : O(1) , SC : O(1)
int buildInMethod(int n) {
    return __builtin_popcount(n); // For long long
}

int main(){
    
    // cout << bruteForce(7);
    // cout << optimal1(7);
    // cout << optimal2(7);
    cout << buildInMethod(7);
    return 0;
}