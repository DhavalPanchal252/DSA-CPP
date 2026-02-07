#include <bits/stdc++.h>
using namespace std;
/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

TC : O( n^2 )
Sc : O(1)
*/
int main(){

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // For printing the  stars stars in each row
        for (int j = 1; j<=N-i; j++)
        {
            cout <<"*";
        }
       
        // For printing the spaces in each row
        for(int j=1 ; j <  2*i+1;j++){
             cout << " ";
        }
        // For printing the  stars stars in each row
        for (int j = 1; j<=N-i; j++)
        {
            cout <<"*";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        // For printing the  stars stars in each row
        for (int j = 0; j<=i; j++)
        {
            cout <<"*";
        }
       
        // For printing the spaces in each row

        for(int j=(N-i)*2-2;j> 0;j--){
            
            cout<<" ";
        }
        
        // For printing the  stars stars in each row
        for (int j = 0; j<=i; j++)
        {
            cout <<"*";
        }
        cout << endl;
    }
    return 0;
}