#include <bits/stdc++.h>
using namespace std;
/*
E 
D E 
C D E 
B C D E 
A B C D E 
*/
int main(){
    int n;
    cin >> n;

    for(int i=0 ; i < n ; i++){
        for(char j = 'E'-i ; j <= 'E' ; j++){
            
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}