#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class MyQueue {
    Node* front;
    Node* rear;
    int currSize;

public:
    MyQueue() {
        front = nullptr;
        rear = nullptr;
        currSize = 0;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);

        if (isEmpty()) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }

        currSize++;
    }

    int dequeue() {
        if (isEmpty()) return -1;

        Node* temp = front;
        int val = temp->data;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        currSize--;

        return val;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int size() {
        return currSize;
    }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {

    MyQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Front: " << q.getFront() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Current Queue: ";
    q.display();

    return 0;
}
