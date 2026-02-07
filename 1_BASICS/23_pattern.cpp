#include <bits/stdc++.h>
using namespace std;
/*
A 
A B 
A B C 
A B C D 
A B C D E 
*/
int main(){
    int n;
    cin >> n; 
    for(int i=1; i<=n ; i++){

        char count='A';
        for(int j =1 ; j<=i ; j++){
            
            cout << count++ << " ";
            
        }
        cout << endl;
    }
    return 0;
}