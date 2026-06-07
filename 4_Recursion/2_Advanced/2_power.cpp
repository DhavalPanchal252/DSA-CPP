#include <bits/stdc++.h>
using namespace std;

double power(double x, long n){

    if(n == 0) return 1;
    if(n == 1) return x;

    double half= power(x , n/2);

    if(n%2 == 0) return half*half;

    return x*half*half;
}


double recursion(double x , long n){

    long num = n;

    if(num < 0) return 1/power(x , -1*num);

    return power(x,num);
}

int main(){
    
    int x , n;

    cin >> x >> n;

    cout << recursion(x , n);
    return 0;
}