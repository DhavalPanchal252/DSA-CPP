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

// TC : O(n) , SC : O(n)
Node* bruteForce(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    vector<int> list;

    Node* temp = head;

    while(temp && temp->next){
        list.push_back(temp->data);
        temp = temp->next->next;
    }

    if(temp) list.push_back(temp->data);

    temp = head->next;

    while(temp && temp->next){
        list.push_back(temp->data);
        temp = temp->next->next;
    }

    if(temp) list.push_back(temp->data);

    temp = head;

    int i=0;
    while(temp){
        temp->data = list[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// TC : O(n) , SC : O(1)

Node* optimal(Node* head){

    if(head == nullptr || head->next == nullptr) return head;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
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