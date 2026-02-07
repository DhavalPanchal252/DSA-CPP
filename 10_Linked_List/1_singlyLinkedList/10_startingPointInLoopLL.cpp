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
Node* bruteForce(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;

    unordered_map<Node* , int> freq; // space : n
    Node* temp = head;

    while(temp){
        if(freq.find(temp) != freq.end()){
            return temp;
        }
        freq[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

//  TC : O(n) , SC : O(1)
Node* optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return nullptr;

    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            // Found cycle, now find starting point
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting point of loop
        }
    }
    return nullptr;
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

    // Node* result = bruteForce(head1);
    Node* result = optimal(head1);

    if(result){
        cout << "Loop starts at node with data: " << result->data;
    } else {
        cout << "No loop found";
    }
    
    return 0;
}