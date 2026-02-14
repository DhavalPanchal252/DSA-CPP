// push : O(n) , pop : O(1)
#include <bits/stdc++.h>
using namespace std;

struct MyStack {
    queue<int> q1;
    queue<int> q2;

    void push(int x) {

        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
    }

    int pop() {
        if (isEmpty()) return -1;

        int ele = q1.front();
        q1.pop();

        return ele;
    }

    int top() {
        if (isEmpty()) return -1;

        int ele = q1.front();

        return ele;
    }

    bool isEmpty() {
        return (q1.empty());
    }
};
int main(){
    
    MyStack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout << "pop : " << st.pop() << endl;

    st.push(7);

    cout << "Top : " << st.top() << endl;
    cout << "Is Empty : " << st.isEmpty() << endl;

    while(!st.isEmpty()){
        cout << st.pop() << " ";
    }

    return 0;
}
