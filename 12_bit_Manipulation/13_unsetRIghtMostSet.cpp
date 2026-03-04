#include <bits/stdc++.h>
using namespace std;

int optimal(int n){
    return (n & (n-1)); // 1001 ^ 1000
}
int main(){
    
    cout << optimal(9); // 1001 --> 1000
    return 0;
}