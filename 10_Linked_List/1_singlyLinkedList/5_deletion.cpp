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

    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);

    Node* mover = head;

    for(int i=1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i]);

        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* deleteAtFront(Node* head){

    if(head == nullptr) return nullptr;

    Node* temp = head;

    head = head->next;
    delete temp;
    return head;
}
Node* deleteAtLast(Node* head){

    if(head == nullptr) return nullptr;

    // Single element
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    // Multiple element
    Node* temp = head;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}
Node* deleteAtPos(Node* head , int pos){
    if(head == nullptr) return nullptr;

    if(pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != nullptr && cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr || temp->next == nullptr) return head;
    Node* curr = temp->next;
    temp->next = curr->next;
    delete curr;
    return head;
}

Node* deleteAtValue(Node* head , int val){
    if(head == nullptr) return nullptr;
    // first element 
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // second onwards
    Node* prev = head;
    Node* temp = head->next;

    while(temp != nullptr && temp->data != val){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr) return head;

    prev->next = temp->next;
    delete temp;
    return head;
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(auto &i : arr) cin >> i ;

    Node* head1 = convertArrToList(arr);

    // Node* head = deleteAtFront(head1);
    // Node* head = deleteAtLast(head1);

    // Node* head = deleteAtPos(head1,0);
    Node* head = deleteAtValue(head1,1);
    while(head){
        cout << head->data <<  " ";
        head = head->next; 
    }

    return 0;
}