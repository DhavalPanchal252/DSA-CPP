#include <bits/stdc++.h>
using namespace std;

stack<int> insert(stack<int> &st , int temp){

    if(st.size() == 0){
        st.push(temp);
        return st;
    }

    int val = st.top();
    st.pop();

    insert(st , temp);

    st.push(val);

    return st;
}

stack<int> reverseStack(stack<int> &st){

    if(st.size() == 1) return st;

    int temp = st.top();
    st.pop();

    reverseStack(st);

    insert(st , temp);

    return st;
}

int main(){

    stack<int> st;

    st.push(5);
    st.push(0);
    st.push(2);
    st.push(1);

    // Print original stack
    stack<int> temp = st;

    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;

    reverseStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}