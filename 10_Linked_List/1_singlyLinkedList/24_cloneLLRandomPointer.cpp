#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int v) {
        val = v;
        next = nullptr;
        random = nullptr;
    }
};

/*
index: 0     1     2     3     4

      [7] → [13] → [11] → [10] → [1]
       ↓     ↓      ↓      ↓     ↓
      null   [0]    [4]    [2]   [0]

*/

// ================= BRUTE (HASHMAP) =================
// TC: O(n)  SC: O(n)

Node* copyRandomListBrute(Node* head) {

    if(!head) return nullptr;

    unordered_map<Node*, Node*> mpp;
    Node* temp = head;

    // create copies
    while(temp){
        mpp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    // connect pointers
    temp = head;
    while(temp){
        mpp[temp]->next = mpp[temp->next];
        mpp[temp]->random = mpp[temp->random];
        temp = temp->next;
    }

    return mpp[head];
}



// ================= OPTIMAL (O(1) SPACE) =================
// TC: O(n)  SC: O(1)

Node* copyRandomListOptimal(Node* head) {

    if(!head) return nullptr;

    Node* temp = head;

    // pass 1: interleave
    while(temp){
        Node* copy = new Node(temp->val);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }

    // pass 2: random
    temp = head;
    while(temp){
        if(temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // pass 3: detach
    temp = head;
    Node* newHead = head->next;
    Node* copy = newHead;

    while(temp){
        temp->next = temp->next->next;
        if(copy->next)
            copy->next = copy->next->next;

        temp = temp->next;
        copy = copy->next;
    }

    return newHead;
}



// ================= BUILD FROM GIVEN INPUT =================
// [[7,null],[13,0],[11,4],[10,2],[1,0]]

Node* buildSample(){

    vector<int> vals = {7,13,11,10,1};
    vector<int> rnd  = {-1,0,4,2,0}; // null = -1

    vector<Node*> nodes;

    for(int v : vals)
        nodes.push_back(new Node(v));

    // next links
    for(int i=0;i<nodes.size()-1;i++)
        nodes[i]->next = nodes[i+1];

    // random links
    for(int i=0;i<nodes.size();i++){
        if(rnd[i] != -1)
            nodes[i]->random = nodes[rnd[i]];
    }

    return nodes[0];
}



// ================= PRINT =================

void printList(Node* head){
    while(head){
        cout << "(" << head->val << ", ";
        if(head->random) cout << head->random->val;
        else cout << "null";
        cout << ") ";
        head = head->next;
    }
    cout << "\n";
}



// ================= MAIN =================

int main(){

    Node* head1 = buildSample();
    Node* head2 = buildSample(); // separate copy for optimal

    cout << "Original:\n";
    printList(head1);

    cout << "\nBrute Copy:\n";
    Node* b = copyRandomListBrute(head1);
    printList(b);

    cout << "\nOptimal Copy:\n";
    Node* o = copyRandomListOptimal(head2);
    printList(o);

    return 0;
}
