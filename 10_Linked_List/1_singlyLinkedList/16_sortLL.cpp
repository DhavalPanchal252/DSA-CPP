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

// TC : O(2n + nlogn) , SC : O(n)
Node* bruteForce(Node* head){

    vector<int> arr;

    Node* temp = head;

    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(),arr.end());

    temp = head;
    int i=0;
    while(temp){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

// TC : O(nlogn) , SC : O(1)
Node* middleElement(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}

Node* mergeSort(Node* left , Node* right){

    Node* head = new Node(-1); 
    Node* temp = head;
    while(left != nullptr && right != nullptr){

        if(left->data < right->data){
            
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if(left) temp->next = left;
    else temp->next = right;

    return head->next;
}

Node* optimal(Node* head) {
    
    if(head == nullptr || head->next == nullptr) return head;

    Node* mid = middleElement(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = optimal(left);
    right = optimal(right);

    return mergeSort(left , right);

}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    // Node* head = bruteForce(head1);
    Node* head = optimal(head1);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}