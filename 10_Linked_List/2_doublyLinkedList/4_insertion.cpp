#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int data1 , Node* prev1 , Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArrToDLL(vector<int> &arr , int n){

    if(n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i=1 ; i<n ; i++){
        Node* temp = new Node(arr[i] , back , nullptr);
        back->next = temp;
        back = back->next;
    }
    return head;
}

Node* insertAtFront(Node* head , int ele){

    Node* temp = new Node(ele,nullptr,head);

    if(head){
        head->prev = temp;
    }
    return temp;
}

Node* insertAtEnd(Node* head , int ele){
    
    Node* temp = new Node(ele,nullptr,nullptr);

    if(head == nullptr) return temp;

    Node* curr = head;

    while(curr->next){
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    return head;
}

Node* insertAtPos(Node* head , int ele , int pos){

    Node* temp = new Node(ele , nullptr , nullptr);

    if(pos == 0){
        temp -> next = head;
        if(head) head->prev = temp;
        return temp;
    }
    
    int cnt = 0 ;

    Node* curr = head;

    // stop at (pos - 1) or last node
    while(curr->next != nullptr && cnt < pos - 1){
        curr = curr->next;
        cnt++;
    }

    // insert AFTER curr
    temp->next = curr->next;
    temp->prev = curr;

    if(curr->next)
        curr->next->prev = temp;

    curr->next = temp;

    return head;
}

Node* insertAtValue(Node* head , int ele , int val){

    Node* temp = new Node(ele , nullptr , nullptr);

    if(head == nullptr) return nullptr;

    if(head -> data == val){

        temp->next = head;
        head->prev = temp;
        return temp;

    }

    Node* curr = head;
    while(curr != nullptr && curr->data != val){
        curr = curr->next;
    }

    if(curr == nullptr){
        delete temp;   // avoid memory leak
        return head;
    }

    Node* back = curr->prev;


    temp->next = curr;
    back->next = temp;
    temp->prev = back;
    curr->prev = temp;

    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int ele;
    cin >> ele;


    Node* node = convertArrToDLL(arr,n);

    // Node* head = insertAtFront(node,ele);
    // Node* head = insertAtEnd(node,ele);
    // Node* head = insertAtPos(node,ele,5);
    Node* head = insertAtValue(node,ele,6);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }    
    return 0;
}