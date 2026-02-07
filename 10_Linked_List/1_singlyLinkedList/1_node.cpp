#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor with data and next
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    // Constructor with only data
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    
    Node* y = new Node(10);

    cout << y << endl;        // address of y
    cout << y->data << endl; // 10
    cout << y->next << endl; // nullptr (0)
    return 0;
}