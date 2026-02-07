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
//  TC : O(n) , SC : O(1)

Node* iterative(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

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

//  TC : O(n) , SC : O(n) stack
Node* recursive(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* newHead = recursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
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