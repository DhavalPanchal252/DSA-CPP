#include <bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int data1 , Node* prev1 , Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArrToDLL(vector<int> &arr , int n){

    if(n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i=1 ; i<n ; i++){
        Node* temp = new Node(arr[i] , back , nullptr);
        back->next = temp;
        back = back->next;
    }
    return head;
}

Node* reverseDDL1(Node* head){

    if(head == nullptr) return nullptr;
    stack<int> st;

    Node* temp = head;
    while(temp != nullptr){
    
        st.push(temp->data);
        temp = temp -> next;
    }

    temp = head;

    while(temp != nullptr){

        temp -> data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* curr = head;
    Node* temp = curr->next;
    curr->next = nullptr;
    curr->prev = temp;

    while (temp != nullptr) {
        // swap prev and next
        temp->prev = temp->next;
        temp->next = curr;
        curr = temp;

        // move using old prev
        temp = temp->prev;
    }

    return curr;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int ele;
    cin >> ele;


    Node* node = convertArrToDLL(arr,n);

    // Node* head = reverseDDL1(node);
    Node* head = reverse(node);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }    
    return 0;
}