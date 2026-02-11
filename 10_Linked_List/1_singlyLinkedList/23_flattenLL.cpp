#include <bits/stdc++.h>
using namespace std;
/*
5 -> 10 -> 19 -> 28
|    |     |     |
7    20    22    35
|          |     |
8          50    40
|                |
30               45

Optimal Flatten:
5 7 8 10 19 20 22 28 30 35 40 45 50 
*/
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


// ================= BRUTE FORCE =================
// TC:  O(N x M log(N x M)) ,    SC: O(2*M*N)

Node* flattenBrute(Node* root) {

    if(!root) return nullptr;

    vector<int> arr;

    Node* temp = root;
    while(temp){ // O(N x M)
        Node* b = temp;
        while(b){
            arr.push_back(b->data);
            b = b->bottom;
        }
        temp = temp->next;
    }

    sort(arr.begin(), arr.end()); // O(N x M log(N x M))

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i=1;i<arr.size();i++){ // O(N x M)
        curr->bottom = new Node(arr[i]);
        curr = curr->bottom;
    }

    return head;
}


// ================= OPTIMAL =================
// TC: O(2*NM)   SC: O(1)

Node* mergeBottom(Node* a, Node* b) { // O(2M)

    Node dummy(-1);
    Node* t = &dummy;

    while(a && b){
        if(a->data < b->data){
            t->bottom = a;
            t = a;
            a = a->bottom;
        } else {
            t->bottom = b;
            t = b;
            b = b->bottom;
        }
        t->next = nullptr;
    }

    if(a) t->bottom = a;
    else t->bottom = b;

    return dummy.bottom;
}

Node* flattenOptimal(Node* root){ // O(N)

    if(!root || !root->next) return root;

    root->next = flattenOptimal(root->next);

    return mergeBottom(root, root->next);  // O(2M)
}


// ================= HELPERS =================

void printBottom(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << "\n";
}


// build sample multi-level list
Node* buildSample(){

    Node* n5 = new Node(5);
    Node* n10 = new Node(10);
    Node* n19 = new Node(19);
    Node* n28 = new Node(28);

    n5->next = n10;
    n10->next = n19;
    n19->next = n28;

    n5->bottom = new Node(7);
    n5->bottom->bottom = new Node(8);
    n5->bottom->bottom->bottom = new Node(30);

    n10->bottom = new Node(20);

    n19->bottom = new Node(22);
    n19->bottom->bottom = new Node(50);

    n28->bottom = new Node(35);
    n28->bottom->bottom = new Node(40);
    n28->bottom->bottom->bottom = new Node(45);

    return n5;
}


// ================= MAIN =================

int main(){

    Node* root1 = buildSample();
    Node* root2 = buildSample(); // build again because optimal mutates links

    cout << "Brute Flatten:\n";
    Node* b = flattenBrute(root1);
    printBottom(b);

    cout << "Optimal Flatten:\n";
    Node* o = flattenOptimal(root2);
    printBottom(o);

    return 0;
}
