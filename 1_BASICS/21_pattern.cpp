#include <bits/stdc++.h>
using namespace std;
/*
1          1
12        21
123      321
1234    4321
12345  54321
123456654321
*/
int main(){
    int n;
    cin >> n;

    for (int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){ // for numbers
            cout << j;
        }

        for(int j=1 ; j <= 2*(n-i) ; j++){ // for spaces
            cout << " "; 
        }

        for (int j = i; j >= 1; j--) { // for numbers
            cout << j;
        }
        cout << endl;
    }
    return 0;
}