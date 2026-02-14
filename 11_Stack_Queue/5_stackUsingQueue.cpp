// push : O(n) , pop : O(1)
#include <bits/stdc++.h>
using namespace std;

struct MyStack {
    queue<int> q;

    void push(int x) {

        int size = q.size();

        q.push(x);

        while(size--){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (isEmpty()) return -1;

        int ele = q.front();
        q.pop();

        return ele;
    }

    int top() {
        if (isEmpty()) return -1;

        int ele = q.front();

        return ele;
    }

    bool isEmpty() {
        return (q.empty());
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
