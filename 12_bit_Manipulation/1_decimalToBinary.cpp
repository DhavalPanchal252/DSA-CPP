#include <bits/stdc++.h>
using namespace std;

// TC : O(logn) , SC : O(1)

// using modulo
string decimalToBinary1(int n){
    
    if(n == 0) return "0";

    string ans ="";

    while(n>0){
        if(n%2 == 1) ans += '1';
        else ans += '0';

        n = n/2;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}
// using char
string decimalToBinary2(int n){
    
    if(n == 0) return "0";

    string ans ="";

    while(n){

        ans += (n%2) + '0'; // if even then '0'+ 0 = '0' else '0'+ 1 = '1'
        n = n/2;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}
// using '&'
string decimalToBinary3(int n){
    
    if(n == 0) return "0";

    string ans ="";

    while(n){

        ans += (n & 1) + '0'; // check last bit : if 0 then even ,else odd
        n = n/2;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

// using '&' and '>>'
string decimalToBinary4(int n){
    
    if(n == 0) return "0";

    string ans ="";

    while(n){

        ans += (n & 1) + '0'; // check last bit : if 0 then even ,else odd
        n = n >> 1; // right shift
    }
    reverse(ans.begin(),ans.end());

    return ans;
}
int main(){
    
    // string ans = decimalToBinary1(12);
    // string ans = decimalToBinary2(12);
    // string ans = decimalToBinary3(12);
    string ans = decimalToBinary4(12);

    for(auto &i : ans) cout << i;
    return 0;
}