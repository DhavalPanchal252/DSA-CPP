

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

// TC : O(max(n,m)) , SC : O(max(n,m))

Node* optimal(Node* l1 , Node* l2){

    l1 = reverseLL(l1);
    l2 = reverseLL(l2);

    Node* a = l1;
    Node* b = l2;

    Node* dummy = new Node(-1);

    Node* curr = dummy;
    int carry = 0;
    
    while(a || b || carry){
        int sum = carry;

        if(a) sum += a->data;
        if(b) sum += b->data;

        carry = sum/10;

        curr->next = new Node(sum%10);
        curr = curr->next;

        if(a) a = a->next;
        if(b) b = b->next;
    }
    // if(carry != 0){
    //     curr->next = new Node(carry);
    // }

    dummy = reverseLL(dummy->next);

    return dummy;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(auto &i : arr1) cin >> i;

    int m;
    cin >> m;

    vector<int> arr2(m);
    for(auto &i : arr2) cin >> i;

    Node* head1 = convertArrToList(arr1, n);
    Node* head2 = convertArrToList(arr2, m);

    
    Node* head = optimal(head1,head2);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}