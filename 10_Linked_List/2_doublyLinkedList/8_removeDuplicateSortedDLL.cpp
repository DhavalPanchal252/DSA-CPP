#include <bits/stdc++.h>
using namespace std;
// Assume DLL is sorted
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

// TC : O(n) , SC : O(1)
Node* optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* curr = head;

    while(curr && curr->next){

        if(curr->data == curr->next->data){
            Node* temp = curr->next;

            curr->next = temp->next;
            if(temp->next) temp->next->prev = curr;

            delete temp;
        }

        else curr = curr->next;
    }

    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    // insert elemetns in sorted order
    for(auto &i : arr) cin >> i;

    Node* node = convertArrToDLL(arr,n);

    Node* head = optimal(node);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}