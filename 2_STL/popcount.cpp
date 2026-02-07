#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {4,5,6,7,10,15};
    // __builtin_popcount() is a set which returns number of 1's in binary

    for(int i=0;i<6;i++)
    {
        cout << __builtin_popcount(a[i]) << endl;
    }
    return 0;
}