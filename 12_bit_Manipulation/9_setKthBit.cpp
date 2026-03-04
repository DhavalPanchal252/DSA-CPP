#include <bits/stdc++.h>
using namespace std;

int optimal(int n , int k){
    return (n | (1 << k)); // 1001 | 0100
}
int main(){
    
    cout << optimal(9,2); // 1001 . set 2th bit from lsb
    return 0;
}