#include <bits/stdc++.h>
using namespace std;
// TC : O(1) , SC : O(1)
bool checkOdd(int n){
    return (n&1);
}

bool checkEven(int n){
    return !(n&1);
}

int main(){
    
    // checkEven(11) ? cout << "YES" : cout << "NO";
    checkOdd(12) ? cout << "YES" : cout << "NO";
    return 0;
}