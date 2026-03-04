#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n = 5; // 0101

    int ones = ~n;
    int twos = ones + 1;

    cout << "1's complement : " << ones << endl; 
    cout << "2's complement : " << twos << endl; 

    return 0;
}