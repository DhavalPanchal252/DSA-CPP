#include <bits/stdc++.h>
using namespace std;
/*
  *  
 *** 
*****
 *** 
  *  
*/
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<n-i-1; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=0;j< 2*i+1;j++){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
         for (int j =0; j<n-i-1; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=(n-i-1)*2+1;j> 0;j--){
            
            cout<<"*";
        }
        
        // For printing the spaces after the stars in each row
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
    return 0;
}