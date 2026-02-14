#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

struct MyStack{
    Node* st = nullptr;
    int currSize = 0;

    void push(int x){
        Node* temp = new Node(x);
        temp->next = st;
        st = temp;
        currSize++;
    }

    int pop(){
        if(isEmpty()) return -1;

        Node* temp = st;
        int val = temp->data;

        st = st->next;
        delete temp;
        currSize--;

        return val;
    }

    int top(){
        if(isEmpty()) return -1;
        return st->data;
    }

    bool isEmpty(){
        return st == nullptr;
    }

    int size(){
        return currSize;
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

    Node* temp = st.st;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
