#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5];
    int a[2][3];
    
// 1-D Array

    cin >>  arr[0] >>  arr[1] >>  arr[2] >>  arr[3] >>  arr[4] ;
    cout << arr[1] << "\n"; // before modification 

    arr[1]+=5;
    cout << arr[1]<< "\n"; // after modification

// 2-D Array

    cin >>  a[0][0] >>  a[0][1] >>  a[0][2] >>  a[1][0] >>  a[1][1] >>  a[1][2] ;

    cout << a[1][1];

    return 0;
}