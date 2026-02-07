#include <bits/stdc++.h>
using namespace std;
/*
  *******
   ***** 
    ***    
     *
*/
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<i; j++)
        {
            cout <<" ";
        }
       
        // For printing the stars in each row
        for(int j=(N-i-1)*2+1;j> 0;j--){
            
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