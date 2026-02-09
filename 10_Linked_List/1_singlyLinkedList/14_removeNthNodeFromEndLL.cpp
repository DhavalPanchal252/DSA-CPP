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

// TC : O(2n) , SC : O(1)
Node* bruteForce(Node* head , int k){

    if(head == nullptr || ((head->next == nullptr) && (k == 1))) return nullptr;

    int cnt = 0;

    Node* temp = head;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    temp = head;

    int result = cnt - k;

    if(result == 0){
        Node* curr = head;
        head = head->next;
        delete curr;
        return head;
    }

    while(--result){
        temp = temp->next;
    }

    Node* curr = temp->next;
    temp->next = curr->next;
    delete curr;
    return head;
}

// TC : O(n) , SC : O(1)
Node* optimal(Node* head , int k){

    if(head == nullptr || (head->next == nullptr && k == 1))
        return nullptr;

    Node* fast = head;

    // move fast k steps ahead
    while(k-- && fast != nullptr){
        fast = fast->next;
    }

    // remove head case
    if(fast == nullptr){
        Node* curr = head;
        head = head->next;
        delete curr;
        return head;
    }

    Node* slow = head;

    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }

    Node* curr = slow->next;
    slow->next = curr->next;
    delete curr;

    return head;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    int k;
    cin >> k;
    Node* head1 = convertArrToList(arr, n);

    // Node* head = bruteForce(head1,k);
    Node* head = optimal(head1,k);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}