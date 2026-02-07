#include <bits/stdc++.h>
using namespace std;

//  TC : O(n) , SC : O(1)
bool optimal(string s, string t){
    int n = s.size();

    unordered_map<char,char> m1,m2; // O(1) bcz only 256 chars

    for(int i=0 ; i<n ; i++){
        if(m1.count(s[i]) && m1[s[i]] != t[i]) return false;
        if(m2.count(t[i]) && m2[t[i]] != s[i]) return false;

        m1[s[i]] = t[i];
        m2[t[i]] = s[i];
    }
    return true;
}

int main(){
    
    string s,t;
    cin >> s;
    cin >> t;

    cout << optimal(s,t);
    return 0;
}