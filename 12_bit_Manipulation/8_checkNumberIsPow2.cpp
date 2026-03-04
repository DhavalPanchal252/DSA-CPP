#include <bits/stdc++.h>
using namespace std;

bool checkNumber(int n){
    return (n > 0 && (n&(n-1)) == 0);
}

int main(){
    
    checkNumber(256) ? cout << "YES" : cout << "NO";
    return 0;
}