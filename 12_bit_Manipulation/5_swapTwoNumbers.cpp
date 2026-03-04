#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int a=5;
    int b=6;

    a = a ^ b;
    b = a ^ b; //  b = (a ^ b) ^ b = a
    a = a ^ b; //  a = a ^ (a ^ b) = b

    cout << a << " " << b ;
    return 0;
}