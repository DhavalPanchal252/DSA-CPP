#include <bits/stdc++.h>
using namespace std;

// Tc : O(n) , SC : O(n)
string prefixToInfix(string s){

    stack<string> st;
    string ans;

    for(int i=s.size()-1 ; i>=0 ; i--){

        if(isalnum(s[i])){
            string temp;
            temp.push_back(s[i]);
            st.push(temp);
        }
        else{
            string temp = "";

            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            temp = "(" + t1 + s[i] + t2 + ")";

            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    
    string ans = prefixToInfix("+a*b-cd");

    for(auto &i : ans) cout << i;
    return 0;
}