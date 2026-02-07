#include <bits/stdc++.h>
using namespace std;
/*
A B C D E 
A B C D 
A B C 
A B 
A 
*/
int main(){
    int n;
    cin >> n; 
    for(int i=n; i>=1 ; i--){

        char count='A';
        for(int j =1 ; j<=i ; j++){
            
            cout << count++ << " ";
            
        }
        cout << endl;
    }
    return 0;
}