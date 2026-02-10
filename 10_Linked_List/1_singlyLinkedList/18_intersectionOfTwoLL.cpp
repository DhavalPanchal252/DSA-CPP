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
// helper — get kth node (for making intersection in demo)
Node* getKth(Node* head, int k){
    while(k-- && head) head = head->next;
    return head;
}

/*
5
1 2 3 4 5
3
9 8 7
2
list1 = 1 2 3 4 5

list2 = 9 8 7

connect list2 tail to index 2 of list1 → node value 3
*/

// TC : O(n*m) , SC : O(1)
Node* bruteForce(Node* headA, Node* headB){
    Node* a = headA;
    Node* b = headB;

    while(a){
        b = headB;
        while(b){
            if(a == b) return a;
            b = b->next;
        }
        a = a->next;
    }
    return nullptr;
}
// TC : O(n+m) , SC : O(1)
Node* optimal(Node* headA, Node* headB){

    Node* a = headA;
    Node* b = headB;

    while(a != b){
        a = a->next;
        b = b->next;

        if(a == b) return a;

        if(a == nullptr) a = headB;
        if(b == nullptr) b = headA;
    }
    return a;
}

int main(){

    int n1; 
    cin >> n1;
    vector<int> arr1(n1);

    for(auto &x : arr1) cin >> x;

    int n2; 
    cin >> n2;
    vector<int> arr2(n2);

    for(auto &x : arr2) cin >> x;

    Node* head1 = convertArrToList(arr1, n1);
    Node* head2 = convertArrToList(arr2, n2);

    // ---- create intersection for testing ----
    // connect tail of list2 to k-th node of list1
    int k; cin >> k;   // give index in list1 (0-based), -1 if no intersection
    if(k != -1){
        Node* join = getKth(head1, k);
        Node* t = head2;
        while(t->next) t = t->next;
        t->next = join;
    }

    Node* ans = bruteForce(head1, head2);
    // Node* ans = optimal(head1, head2);

    if(ans) cout << "Intersection at node with value: " << ans->data;
    else cout << "No intersection";

    return 0;
}
