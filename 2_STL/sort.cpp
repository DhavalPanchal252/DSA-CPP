#include <bits/stdc++.h>
using namespace std;

int main(){
    // sort(start , end) [start,end)
    int a[] = {1,4,3,2,9,5};
    int n=6;

    // Ascending order
    sort(a,a+n);

    for(int i=0 ; i<n;i++){
        cout << a[i] <<" ";
    }
    cout << endl;

    // Descending order
    sort(a,a+n,greater<int>());
    
    for(int i=0 ; i<n;i++){
        cout << a[i] <<" ";
    }
    return 0;
}