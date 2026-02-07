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
    if(head == nullptr || head->next == nullptr) return false;

    unordered_map<Node* , int> freq; // space : n
    Node* temp = head;

    while(temp){
        if(freq.find(temp) != freq.end()){
            return true;
        }
        freq[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//  TC : O(n) , SC : O(1)
bool optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return false;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);
    
    // Create a cycle: connect last node to second node (optional for testing)
    if(head1 && head1->next){
        Node* last = head1;
        while(last->next) last = last->next;
        last->next = head1->next; // Creates cycle
    }

    // cout << bruteForce(head1);
    cout << optimal(head1);
    return 0;
}