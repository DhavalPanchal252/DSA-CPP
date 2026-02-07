#include <bits/stdc++.h>
using namespace std;
// nth term of fibonacci
int fibo(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n) <<endl; // only gives nth term


    // print first n Fibonacci numbers
    for(int i = 0; i < n; i++) {
        cout << fibo(i) << " ";
    }
    return 0;
}