#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(char i : s){

        if(i == '(' || i == '{' || i == '[') {
            st.push(i);
        }
        else{
            if(st.empty()) return false;

            if((i == ')' && st.top() == '(') ||
               (i == ']' && st.top() == '[') ||
               (i == '}' && st.top() == '{')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

int main(){
    
    string s;
    getline(cin, s);

    if(isValid(s)) 
        cout << "Balanced";
    else 
        cout << "Not Balanced";

    return 0;
}
