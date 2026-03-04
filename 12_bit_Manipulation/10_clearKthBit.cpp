#include <bits/stdc++.h>
using namespace std;

int optimal(int n , int k){
    return (n & ~(1 << k)); // 1101 & 1011
}
int main(){
    
    cout << optimal(13,2); // 1101 . clear 2th bit from lsb
    return 0;
}