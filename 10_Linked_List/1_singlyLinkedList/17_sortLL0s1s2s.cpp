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

// TC : O(n) , SC : O(1)
Node* optimal1(Node* head){

    if(head == nullptr || head->next == nullptr) return head;
        
    Node* temp = head;
    
    int ones = 0;
    int zeros = 0;
    int twos = 0;
    
    while(temp){
        if(temp->data == 0) zeros++;
        else if(temp->data == 1) ones++;
        else twos++;
        
        temp = temp->next;
    }
    
    temp = head;
    
    while(zeros--){
        temp->data = 0;
        temp = temp->next;
    }
    while(ones--){
        temp->data = 1;
        temp = temp->next;
    }
    while(twos--){
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}

// TC : O(n) , SC : O(1)
Node* optimal2(Node* head) {
        
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* temp = head;
    
    Node* ones = new Node(-1);
    Node* zeros = new Node(-1);;
    Node* twos = new Node(-1);
    
    Node* oneTails = ones;
    Node* zeroTails = zeros;
    Node* twoTails = twos;
    
    while(temp){
        if(temp->data == 0){
            zeroTails->next = temp;
            zeroTails = zeroTails->next;
        }
        else if(temp->data == 1){
            oneTails->next = temp;
            oneTails = oneTails->next;  
        }
        else{
            twoTails->next = temp;
            twoTails = twoTails->next;
        }
        temp = temp->next;
    }
    twoTails->next = nullptr;
    
    zeroTails->next = (ones->next) ? ones->next : twos->next;
    oneTails->next  = twos->next;
    
    Node* t = zeros;
    zeros = zeros->next;

    delete ones;
    delete twos;
    delete t;
    
    
    return zeros;
    
}


int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node* head1 = convertArrToList(arr, n);

    
    // Node* head = optimal1(head1);
    Node* head = optimal2(head1);
   
    
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}