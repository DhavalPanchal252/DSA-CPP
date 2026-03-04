#include <bits/stdc++.h>
using namespace std;

// TC : O(log n), SC : O(log n)  (string storage)
bool bruteForce(int n,int k){
    
    string ans = "";
    while(n){
        ans += (n & 1) + '0';
        n = n >> 1;
    }

    if(k >= ans.size()) return false;

    return (ans[k] == '1');
}
// using left shift
// TC : O(1), SC : O(1)
bool optimal1(int n,int k){
    return (n & (1 << k)) != 0;
}
// using right shift
// TC : O(1), SC : O(1)
bool optimal2(int n,int k){
    return ((n >> k) & 1) != 0;
}
int main(){
    
    // bruteForce(5,0) ? cout << "YES" : cout << "NO";
    // optimal1(5,0) ? cout << "YES" : cout << "NO";
    optimal2(5,0) ? cout << "YES" : cout << "NO";
    return 0;
}