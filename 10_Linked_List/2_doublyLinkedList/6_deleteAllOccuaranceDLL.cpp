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

Node* optimal(Node* head , int x){

    Node* temp = head;

    while(temp){
        if(temp->data == x){
            
            Node* del = temp;
            Node* prevNode = del->prev;
            Node* nextNode = del->next;

            if(temp == head){
                head = nextNode;
                if(head) head->prev = nullptr;
            }
            else{
                if(prevNode) prevNode->next = nextNode;
                if(nextNode) nextNode->prev = prevNode;
            }

            delete del;
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int ele;
    cin >> ele;


    Node* node = convertArrToDLL(arr,n);

    Node* head = optimal(node,ele);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }    
    return 0;
}