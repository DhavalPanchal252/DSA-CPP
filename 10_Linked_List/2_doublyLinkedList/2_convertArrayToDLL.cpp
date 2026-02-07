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

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i=1 ; i<n ; i++){
        Node* temp = new Node(arr[i] , back , nullptr);
        back->next = temp;
        back = back->next;
    }
    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;


    Node* node = convertArrToDLL(arr,n);

    while(node){
        cout << node->data << " ";
        node = node->next;
    }    
    return 0;
}