#include <bits/stdc++.h>
using namespace std;

int optimal(int start ,int goal){
    
    int ans = start ^ goal; // 0111 ^ 1000 = 1111

    // count no of set bits in answer
    int cnt = 0;

    while(ans){
        cnt += (ans&1);
        ans = ans >> 1;
    }

    return cnt; // 4 bits swap required to get goal
}

int main(){
    
    cout << optimal(7,8);
    return 0;
}