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

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i=1 ; i<n ; i++){
        Node* temp = new Node(arr[i] , back , nullptr);
        back->next = temp;
        back = back->next;
    }
    return head;
}

Node* deleteAtFront(Node* head){

    if(head == nullptr) return head;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}

Node* deleteAtEnd(Node* head){

    if(head == nullptr) return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while(temp->next->next){
        temp = temp->next ; 
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteAtPos(Node* head , int pos){
    if(head == nullptr) return nullptr;
    
    int cnt = 0;
    Node* temp = head;
    
    if(pos == 0){
        head = head->next;
        if(head) head->prev = nullptr;
        delete temp;
        return head;
    }

    while(temp != nullptr && cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    if(temp == nullptr || temp->next == nullptr) return head;

    if(temp->next->next == nullptr){
        delete temp->next;
        temp->next = nullptr;
        return head;
    }

    Node* curr = temp->next;
    curr->next->prev = temp;
    temp->next = curr->next;
    delete curr;
    return head;
}

// Node* deleteAtValue(Node* head , int val){

//     if(head == nullptr) return nullptr;

//     Node* temp = head;

//     if(head->data == val){
//         head = head->next;
//         if(head) head->prev = nullptr;
//         delete temp;
//         return head;
//     }

//     while(temp != nullptr && temp->next != nullptr && temp->next->data != val){
//         temp = temp->next;
//     }

    
//     if(temp == nullptr || temp->next == nullptr) return head;    
    
//     if(temp->next->next == nullptr){
//         delete temp->next;
//         temp->next = nullptr;
//         return head;
//     }

//     Node* curr = temp->next;
//     curr->next->prev = temp;
//     temp->next = curr->next;
//     delete curr;
//     return head;

// }
Node* deleteAtValue(Node* head, int val) {
    if(head == nullptr) return nullptr;

    Node* curr = head;

    // find node with given value
    while(curr != nullptr && curr->data != val){
        curr = curr->next;
    }

    // value not found
    if(curr == nullptr) return head;

    // deleting head
    if(curr == head){
        head = head->next;
        if(head) head->prev = nullptr;
    }
    else{
        curr->prev->next = curr->next;
        if(curr->next)
            curr->next->prev = curr->prev;
    }

    delete curr;
    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;


    Node* node = convertArrToDLL(arr,n);

    // Node* head = deleteAtFront(node);
    // Node* head = deleteAtEnd(node);
    // Node* head = deleteAtPos(node,5);
    Node* head = deleteAtValue(node,3);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }    
    return 0;
}