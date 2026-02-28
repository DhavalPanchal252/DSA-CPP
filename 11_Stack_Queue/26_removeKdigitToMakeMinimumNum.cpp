#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC : O(n)
string optimal(string s , int k){

    int n = s.size();
    stack<char> st;

    for(auto &i : s){
        while(!st.empty() && k>0 && i < st.top()){
            st.pop();
            k--;
        }

        if(st.empty() && i == '0') continue;
        else st.push(i);
    }

    while(!st.empty() && k>0){
        st.pop();
        k--;
    }

    if(st.empty()) return "";
    string ans = "";

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    
    string s;
    getline(cin,s);

    int k;
    cin >> k;

    string ans = optimal(s,k);

    for(auto &i : ans) cout << i;
    return 0;
}