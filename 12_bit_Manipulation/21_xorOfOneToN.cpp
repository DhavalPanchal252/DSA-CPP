#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC :(1)
int bruteForce(int n){

    int xorr = 0 ;

    for(int i=1 ; i<=n ; i++){
        xorr ^= i;
    }
    return xorr;
}

// TC : O(1) , SC :(1)
int optimal(int n){

    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}

int main(){
    // cout << bruteForce(1);
    cout << optimal(2);
    return 0;
}