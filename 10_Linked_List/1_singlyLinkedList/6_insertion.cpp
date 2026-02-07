#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToList(vector<int> &arr, int n){
    if(n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < n; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node* insertAtBeginning(Node* head , int val){

    Node* temp = new Node(val);

    if(head == nullptr) return temp;

    temp->next = head;
    head = temp;
    return head;
}

Node* insertAtLast(Node* head , int val){

    Node* temp = new Node(val);

    if(head == nullptr) return temp;

    Node* curr = head;

    while(curr->next){
        curr = curr->next;
    }

    curr->next = temp;
    return head;
}

Node* insertAtPos(Node* head , int val , int pos){
    Node* temp = new Node(val);

    if(pos == 0){
        temp->next = head;
        return temp;
    }

    int cnt = 0;

    Node* curr = head;

    while(curr != nullptr && cnt < pos-1){
        curr = curr->next;
        cnt++;
    }

    // if position out of bound
    if(curr == nullptr){
        delete temp;
        return head;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* insertAfterGivenValue(Node* head , int val, int given){

    Node* temp = new Node(val);

    if(head == nullptr){
        delete temp;
        return nullptr;
    }

    Node* curr = head;
    while(curr != nullptr && curr->data != given){
        curr = curr->next;
    }

    if(curr == nullptr){
        delete temp;
        return head;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* insertBeforeGivenValue(Node* head , int val , int given){

    Node* temp = new Node(val);

    if(head == nullptr){
        delete temp;
        return nullptr;
    }

    Node* curr = head;

    if(head->data == given){
        temp ->next = head;
        return temp;
    }

    while(curr->next != nullptr && curr->next->data != given){
        curr = curr->next;
    }

    if(curr->next == nullptr){
        delete temp;
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;

}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    int val;
    cin >> val;
    // Node* head = insertAtBeginning(head1 , val);
    // Node* head = insertAtLast(head1 , val);
    // Node* head = insertAtPos(head1 , val , 0);
    // Node* head = insertAfterGivenValue(head1 , val , 6);
    Node* head = insertBeforeGivenValue(head1 , val , 6);
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}