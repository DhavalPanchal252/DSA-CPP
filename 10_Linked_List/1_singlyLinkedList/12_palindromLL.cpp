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
//  TC : O(n) , SC : O(n)
bool bruteForce(Node* head){

    if(head == nullptr || head->next == nullptr) return true;

    stack<int> st;
    Node* temp = head;

    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp){
        if(temp->data != st.top()) return false;

        st.pop();
        temp = temp->next;
    }
    return true;
}
//  TC : O(n) , SC : O(1)
Node* reverse(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* curr = head;
    Node* t = nullptr;
    
    while(curr){
        Node* temp = curr->next;

        curr->next = t;
        t = curr;
        curr = temp;
    }
    return t;
}
bool optimal(Node* head) {
    
    if(head == nullptr || head->next == nullptr) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){

        slow = slow->next;
        fast = fast->next->next;
    }

    // skip middle element for odd length list
    if(fast) slow = slow->next;

    Node* result = reverse(slow);

    while(result){

        if(head->data != result->data) return false;
        head = head->next;
        result = result->next;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    // cout << bruteForce(head1);
    cout <<  optimal(head1);

    return 0;
}