#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC : O(n)
string optimal(string s){
    string str = "";
    int cnt = 0 ;

    for(auto &i : s){
        if(i == '('){
            cnt++;
            if(cnt>1) str.push_back(i);
        }
        else{
            cnt--;
            if(cnt>0) str.push_back(i);
        }
    }
    return str;
}

int main(){
    
    string s ;
    cin >> s;
    
    string result = optimal(s);

    for(auto &i :result) cout << i;
    return 0;
}