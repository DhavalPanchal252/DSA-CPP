#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
    TC: O(n)  -> visit every node once
    SC: O(h)  -> recursion stack, h = height of tree
*/

bool isSameTree(Node* p, Node* q) {

    if (p == nullptr || q == nullptr)
        return p == q;

    // check preorder of both
    return (p->data == q->data) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {

    /*
            Tree 1           Tree 2

               1                1
              / \              / \
             2   3            2   3
    */

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isSameTree(root1, root2))
        cout << "Trees are Same";
    else
        cout << "Trees are Not Same";

    return 0;
}