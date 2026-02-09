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

// TC : O(n) , SC : O(1)
Node* optimal1(Node* head){

    Node* fast = head;
    Node* slow = head;
    Node* temp = nullptr;

    if(head == nullptr || head->next == nullptr) return nullptr;

    while(fast != nullptr && fast->next != nullptr){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    temp->next = slow->next;
    delete slow;
    return head;
}

// TC : O(n) , SC : O(1)
Node* optimal2(Node* head){

    Node* fast = head;
    Node* slow = head;

    if(head == nullptr || head->next == nullptr) return nullptr;

    fast = fast->next->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return head;
}


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    // Node* head = optimal1(head1);
    Node* head = optimal2(head1);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}