#include <bits/stdc++.h>
using namespace std;

stack<int> insert(stack<int> &st , int temp){

    if(st.size() == 0 || st.top() <= temp){
        st.push(temp);
        return st;
    }

    int val = st.top();
    st.pop();

    insert(st , temp);

    st.push(val);

    return st;
}

stack<int> sortStack(stack<int> &st){

    if(st.size() == 1) return st;

    int temp = st.top();
    st.pop();

    sortStack(st);

    insert(st , temp);

    return st;
}

int main(){

    stack<int> st;

    st.push(5);
    st.push(0);
    st.push(2);
    st.push(1);

    sortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}