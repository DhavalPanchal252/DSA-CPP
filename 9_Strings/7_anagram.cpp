#include <bits/stdc++.h>
using namespace std;

//  TC : O(nlogn) , SC : O(1)
bool bruteForce(string s , string t){

    if(s.size() != t.size()) return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s == t) return true;
    else return false;
}

//  TC : O(n) , SC : O(1)
bool optimal(string s , string t){

    if(s.size() != t.size()) return false;

    vector<int> freq(26,0);

    for(int i=0 ; i<s.size() ; i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for(int i=0 ; i<26 ; i++){
        if(freq[i] != 0) return false;
    }

    return true;
}

int main(){
    
    string s,t;
    cin >> s;
    cin >> t;

    // cout << bruteForce(s,t);
    cout << optimal(s,t);
    return 0;
}