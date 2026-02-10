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
        next= nullptr;
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
Node* reverseLL(Node* head){

    // if(head == nullptr || head->next == nullptr) return head;

    Node* t = nullptr;
    Node* curr = head;

    while(curr){
        Node* temp = curr->next;

        curr->next = t;
        t = curr;
        curr = temp;
    }

    return t;
}

// TC : O(n) , SC : O(1)
Node* iterative(Node* head){

    head = reverseLL(head);

    Node* temp = head;

    int carry = 1;

    while(temp){
        int result = temp->data + carry;

        if(result == 10){
            temp->data = 0;
            carry = 1;
        }
        else{
            temp->data = result;
            carry = 0;
            break;
        }
        if(temp->next == nullptr && carry == 1){
            temp->next = new Node(1);
            break;
        }
        temp = temp->next;
    }

    head = reverseLL(head);

    return head;
}

int helper(Node* temp){

    if(temp == nullptr) return 1;

    int carry = helper(temp->next);

    int result = temp->data + carry;

    if(result == 10){
        temp->data = 0;
        return 1;
    }
    temp->data = result;
    return 0;
}

// TC : O(n) , SC : O(n)
Node* recursive(Node* head){
    
    int carry = helper(head);

    if(carry == 1){
        Node* temp = new Node(1);
        temp->next = head;
        head = temp;
    }
    return head;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    // Node* head = iterative(head1);
    Node* head = recursive(head1);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}