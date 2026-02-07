#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC : O(n)
string optimal(string s){

    string ans = "";

    for(int i = s.size()-1 ; i>=0 ; i--){
        
        if(int(s[i])%2 != 0){
            return s.substr(0 , i + 1);
        }
    }
    return ans;
}

int main(){
    
    string s ;
    cin >> s;
    
    string result = optimal(s);

    for(auto &i :result) cout << i;
    return 0;
}