#include <bits/stdc++.h>
using namespace std;

// Tc : O(n) , SC : O(n)
string postToPrefix(string s){

    stack<string> st;
    string ans;

    for(int i=0 ; i<s.size() ; i++){

        if(isalnum(s[i])){
            string temp;
            temp.push_back(s[i]);
            st.push(temp);
        }
        else{
            string temp = "";

            string t2 = st.top();
            st.pop();
            string t1 = st.top();
            st.pop();

            temp = string(1,s[i]) + t1 + t2 ;

            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    
    string ans = postToPrefix("abcd-*+");

    for(auto &i : ans) cout << i;
    return 0;
}