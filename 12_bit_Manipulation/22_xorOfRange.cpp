#include <bits/stdc++.h>
using namespace std;

// TC : O(1) , SC :(1)
int optimal(int n){

    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}
// l = 4 , r = 7

// (1^2^3) ^ (1^2^3^4^5^6^7) = (4^5^6^7)
int findRangeXOR(int l , int r){
    return optimal(l-1) ^ optimal(r);
}

int main(){
    
    cout << findRangeXOR(1,3);
    return 0;
}