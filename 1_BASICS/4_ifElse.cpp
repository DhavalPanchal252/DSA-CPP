#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a,b,c;

    cin >> a >> b >> c;

    if(a>b)
    {
        if(a>c)
            cout << "largest number : " << a ;
        else
            cout << "largest number : " << c ;
    }
    else
    {
        if(b>c)
            cout << "largest number : " << b ;
        else
            cout << "largest number : " << c ; 
    }
}