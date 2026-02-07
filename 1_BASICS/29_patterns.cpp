#include <bits/stdc++.h>
using namespace std;
/*
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
int main(){
    int n;
    cin >> n;

    for (int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){
            cout << "*";
        }

        for(int j=1 ; j <= 2*(n-i) ; j++){
            cout << " "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        // For printing the  stars stars in each row
        for (int j = 1; j<=n-i; j++)
        {
            cout <<"*";
        }
       
        // For printing the spaces in each row
        for(int j=1 ; j <  2*i+1;j++){
             cout << " ";
        }
        // For printing the  stars stars in each row
        for (int j = 1; j<=n-i; j++)
        {
            cout <<"*";
        }
        cout << endl;
    }
    return 0;
}