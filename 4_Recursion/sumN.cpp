#include <bits/stdc++.h>
using namespace std;

int sumN(int n){
    if(n == 0) return 0;
    return n + sumN(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << "Sum : " << sumN(n);   
    return 0;
}