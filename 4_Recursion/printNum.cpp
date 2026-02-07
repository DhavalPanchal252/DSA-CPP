#include <bits/stdc++.h>
using namespace std;

void printN(int n){

    if(n == 0) return;

    printN(n-1);

    cout << n << " ";
}
void print1(int n){

    if(n == 0) return;

    
    cout << n << " ";
    print1(n-1);
}

int main(){
    int n;
    cin >> n;
    printN(n); // 1 to 5
    cout << endl; // 5 to 1 
    print1(n);
}
// int printN(int i, int n){

//     if(i>n) return 1;
//     cout << i << " ";

//     printN(i+1,n);
// }

// int main(){
    
//     int n;
//     cin >> n;

//     printN(1,n);
//     return 0;
// }

