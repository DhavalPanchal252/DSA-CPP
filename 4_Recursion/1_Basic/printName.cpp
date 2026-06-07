#include <bits/stdc++.h>
using namespace std;

int printN(int i, int n){

    if(i>n) return 1;
    cout << "Dhaval" << endl;

    printN(i+1,n);
}

int main(){
    
    int n;
    cin >> n;

    printN(1,n);
    return 0;
}