#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for(char ch : s) {
        
        // push opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        // handle closing brackets
        else if(ch == ')' || ch == '}' || ch == ']') {
            if(st.empty()) 
                return false;

            char top = st.top();
            st.pop();

            // mismatch check
            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '['))
                return false;
        }
    }

    return st.empty();
}

int main() {
    string s;
    getline(cin, s);

    if(isBalanced(s)) 
        cout << "Balanced";
    else 
        cout << "Not Balanced";

    return 0;
}
