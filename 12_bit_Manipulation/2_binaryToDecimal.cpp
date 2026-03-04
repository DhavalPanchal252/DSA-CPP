#include <bits/stdc++.h>
using namespace std;
// assume string has < 32 bits ... if not then use long long
// TC : O(n) , SC : O(1)
int binaryToDecimal1(string s){

    int ans = 0;
    int n = s.size();
    int power = 1;

    for(int i= n-1 ; i>=0 ; i--){
        if(s[i] == '1'){
            ans += power;
        }
        else ans += 0;
        power *= 2;
    }
    return ans;
}

int binaryToDecimal2(string s){

    int ans = 0;

    for(auto &c : s){
        ans = ans*2 + (c - '0');
    }
    return ans;
}
int main(){
    
    // cout << binaryToDecimal1("1100");
    cout << binaryToDecimal2("1100");
    return 0;
}