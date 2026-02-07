#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<char,int> p1 , pair<char,int> p2){

    if(p1.second > p2.second) return true;
    if(p1.second < p2.second) return false;

    return p1.first < p2.first;

}
//  TC : O(n + klogk) , SC : O(n)
string optimal(string &s){

    int n = s.size();

    unordered_map<char,int> mapp;

    for(int i=0 ; i<n ; i++){ //n
        mapp[s[i]]++;
    }

    vector <pair<char,int>> vec(mapp.begin() , mapp.end()); // k : no of unique char , k<=256

    sort(vec.begin() , vec.end() , comparator); // klogk

    string ans = "";//n

    for(auto &i : vec){ // n
        ans.append(i.second,i.first);
    }
    return ans;
}

int main(){
    
    string s ;
    cin >> s; 

    string ans = optimal(s);

    for(auto &i : ans) cout << i;
    return 0;
}