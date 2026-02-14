// push : O(n) and pop : O(1)
#include <bits/stdc++.h>
using namespace std;

struct MyQueue {
    stack<int> st1;
    stack<int> st2;
    int currSize = 0;

    void enqueue(int x) {

        // Move everything to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Push new element
        st1.push(x);
        currSize++;

        // Move back to st1
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int dequeue() {
        if (isEmpty()) return -1;

        int ele = st1.top();
        st1.pop();
        currSize--;

        return ele;
    }

    int peek() {
        if (isEmpty()) return -1;
        return st1.top();
    }

    bool isEmpty() {
        return st1.empty();
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
