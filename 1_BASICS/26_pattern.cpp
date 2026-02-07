#include <bits/stdc++.h>
using namespace std;
/*
        A 
      A B A 
    A B C B A 
  A B C D C B A 
A B C D E D C B A 

*/
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // For printing the spaces before stars in each row
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
       
        // For printing the Chars in each row
        char ch = 'A';
        int breakpoint = (2*i+1)/2;

        for(int j=0 ; j <  2*i+1;j++){
             cout << ch;

             if(j < breakpoint) ch++;
             else ch--;

        }
        // For printing the spaces after the stars in each row
         for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        }
        cout << endl;
    }
    return 0;
}