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

Node* convertArrToList(vector<int> &arr){

    Node* head = new Node(arr[0]);

    Node* mover = head;

    for(int i=1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i]);

        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(auto &i : arr) cin >> i ;

    Node* head = convertArrToList(arr);

// Traversal of the element in linked list
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}