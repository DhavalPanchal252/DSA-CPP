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

/*==================================================
    METHOD 1: Recursive

    TC: O(h)
    SC: O(h)

    h = Height of BST
==================================================*/

Node* LCA_Recursive(Node* root, Node* p, Node* q) {

    if (root == nullptr)
        return nullptr;

    if (root->data > p->data &&
        root->data > q->data)
        return LCA_Recursive(root->left, p, q);

    if (root->data < p->data &&
        root->data < q->data)
        return LCA_Recursive(root->right, p, q);

    return root;
}

/*==================================================
    METHOD 2: Iterative

    TC: O(h)
    SC: O(1)

    h = Height of BST
==================================================*/

Node* LCA_Iterative(Node* root, Node* p, Node* q) {

    while (root) {

        if (root->data > p->data &&
            root->data > q->data) {

            root = root->left;
        }
        else if (root->data < p->data &&
                 root->data < q->data) {

            root = root->right;
        }
        else {
            return root;
        }
    }

    return nullptr;
}

int main() {

    /*
                  6
                /   \
               2     8
              / \   / \
             0   4 7   9
                / \
               3   5

        p = 2
        q = 8

        LCA = 6
    */

    Node* root = new Node(6);

    root->left = new Node(2);
    root->right = new Node(8);

    root->left->left = new Node(0);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(9);

    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node* p = root->left;   // 2
    Node* q = root->right;  // 8

    Node* ans1 = LCA_Recursive(root, p, q);
    Node* ans2 = LCA_Iterative(root, p, q);

    cout << "Recursive LCA : " << ans1->data << endl;
    cout << "Iterative LCA : " << ans2->data << endl;

    return 0;
}