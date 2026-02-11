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
Node* reverse(Node* head){
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
//  TC : O(n) , SC : O(1) 
Node* reverseKGroup(Node* head , int k){

    if(head == nullptr || k == 1) return head;
        
    Node* curr = head;
    Node* temp = head;
    Node* rev = nullptr;
    int cnt = 0;

    while(temp){
        cnt++;
        Node* x = temp;
        temp = temp->next;

        if(cnt == k){
            x->next = nullptr;
            rev = reverse(curr);
            temp = reverseKGroup(temp,k);

            curr->next = temp;

            return rev;
        }
    }
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

    Node* head = reverseKGroup(head1,k);
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}