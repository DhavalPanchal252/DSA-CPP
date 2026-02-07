#include <bits/stdc++.h>
using namespace std;

/*
T(n) = T(n−1) + T(n−2) + 1
TC : O( 2^n ) or Omega( 2^(n/2) ) 
Sc : O(n).... fib(n) → fib(n-1) → fib(n-2) → ... → fib(1)
*/
int fib(int n){
    
    if(n==0) return 0;
    if(n==1) return 1;
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main() {
    int n ;
    cin >> n;
    
    cout << fib(n);
    return 0;
}
