#include <bits/stdc++.h>
using namespace std;

// Tc : O(n) , SC : O(n)
int priority(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}
string infixToPostfix(string s){

    stack<char> st;
    string ans;

    for(auto &i : s){
        if(isalnum(i)) ans.push_back(i);
        else if(i == '(') st.push(i);
        else if(i == ')'){
            while(!st.empty() && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() &&
                (priority(i) < priority(st.top()) ||
                (priority(i) == priority(st.top()) && i != '^'))){
                    ans.push_back(st.top());
                    st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    
    string ans = infixToPostfix("a+b*(c-d)");

    for(auto &i : ans) cout << i;
    return 0;
}