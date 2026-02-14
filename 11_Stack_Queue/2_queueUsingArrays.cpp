#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct MyQueue {
    vector<int> arr;
    int front;
    int rear;
    int currSize;
    int n;

    MyQueue(int n1) {
        n = n1;
        arr = vector<int>(n);
        front = -1;
        rear = -1;
        currSize = 0;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == n;
    }

    void enqueue(int x) {
        if (isFull()) return;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % n;
        }

        arr[rear] = x;
        currSize++;
    }

    void dequeue() {
        if (isEmpty()) return;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }

        currSize--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }

    int size() {
        return currSize;
    }
};

int main(){
    
    MyQueue q(4);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.enqueue(7);
    cout << "getFront : " << q.getFront() << endl;
    cout << "getRear : " << q.getRear() << endl;
    cout << "isEmpty : " << q.isEmpty() << endl;
    cout << "isFull : " << q.isFull() << endl;
    for(auto &i : q.arr) cout << i << " ";
    return 0;
}