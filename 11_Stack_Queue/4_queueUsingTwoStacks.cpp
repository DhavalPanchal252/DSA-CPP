// push : O(1) and pop : O(n)
#include <bits/stdc++.h>
using namespace std;

struct MyQueue {
    stack<int> st1;
    stack<int> st2;
    int currSize = 0;

    void enqueue(int x) {

        st1.push(x);
        currSize++;
    }

    int dequeue() {
        if (isEmpty()) return -1;

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        int ele = st2.top();
        st2.pop();
        currSize--;

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }

    int peek() {
        if (isEmpty()) return -1;

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        int ele = st2.top();

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }

    bool isEmpty() {
        return (st1.empty());
    }

    int size() {
        return currSize;
    }
};

int main() {
    
    MyQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.enqueue(7);

    cout << "peek : " << q.peek() << endl;
    cout << "isEmpty : " << q.isEmpty() << endl;
    cout << "size : " << q.size() << endl;

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
