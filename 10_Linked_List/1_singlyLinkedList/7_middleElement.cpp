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
//  TC : O(n + n/2) , SC : O(1)
Node* bruteForce1(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    int cnt = 0 ;

    Node* temp = head;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    int half = int(cnt/2) + 1;

    int cnt1 =0 ;
    temp = head;

    while(cnt1 < half-1){
        temp = temp->next;
        cnt1++;
    }
    return temp;
}
// this is better
//  TC : O(n + n/2) , SC : O(1)
Node* bruteForce2(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    int cnt = 0 ;

    Node* temp = head;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    int half = cnt/2;

    temp = head;

    while(half){
        temp = temp->next;
        half--;
    }
    
    return temp;
}

// Tortoise and Hare Algorithm

//  TC : O(n/2) , SC : O(1)
Node* optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return head;
    
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr ){

        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    // Node* head = bruteForce1(head1);
    // Node* head = bruteForce2(head1);
    Node* head = optimal(head1);
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}