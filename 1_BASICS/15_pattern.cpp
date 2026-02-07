#include <bits/stdc++.h>
using namespace std;

/*
   *     
  ***    
 ***** 
*******  
*/

int main(){
    int n;
    cin >> n; //4
    for (int i=0; i<n; i++){

        for (int j = 0; j < n-i-1; j++){ // for spaces 
            cout << " ";
        }

        for (int j= 0; j < 2*i + 1 ; j++){ // for stars
            cout << "*" ;
        }

        for (int j = 0; j < n-i-1; j++){ // for spaces 
            cout << " ";
        }
    cout << endl;
    }
    return 0;
}