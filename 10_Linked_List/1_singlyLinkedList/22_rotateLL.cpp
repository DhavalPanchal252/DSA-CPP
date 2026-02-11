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
Node* optimal(Node* head , int k){

    if(head == nullptr || head->next == nullptr || k==0) return head;
    Node* temp = head;

    int cnt = 0;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    int r = k % cnt;

    Node* fast = head;

    while(r--){
        fast = fast->next;
    }

    Node* slow = head;

    while(fast->next){
        slow = slow->next;
    
        fast = fast->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = nullptr;

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

    Node* head = optimal(head1,k);
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}