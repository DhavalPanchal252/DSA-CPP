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
==================================================
    Recover BST

    Case 1:
    Adjacent Nodes Swapped

    Example:
    1 3 2 4

    first = 3
    middle = 2

    Swap(first, middle)

--------------------------------------------------

    Case 2:
    Non-Adjacent Nodes Swapped

    Example:
    1 5 3 4 2 6

    first = 5
    last = 2

    Swap(first, last)

--------------------------------------------------

    TC: O(n)
    SC: O(h)
==================================================
*/

Node* prevNode;
Node* firstNode;
Node* middleNode;
Node* lastNode;

void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);

    if (prevNode != nullptr &&
        prevNode->data > root->data) {

        if (firstNode == nullptr) {

            firstNode = prevNode;
            middleNode = root;
        }
        else {

            lastNode = root;
        }
    }

    prevNode = root;

    inorder(root->right);
}

void recoverTree(Node* root) {

    firstNode = nullptr;
    middleNode = nullptr;
    lastNode = nullptr;

    prevNode = new Node(INT_MIN);

    inorder(root);

    if (firstNode && lastNode)
        swap(firstNode->data, lastNode->data);

    else if (firstNode && middleNode)
        swap(firstNode->data, middleNode->data);
}

void inorderTraversal(Node* root) {

    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    /*
            Original BST

                  3
                 / \
                1   4
                   /
                  2

        Inorder:
        1 3 2 4

        Swapped Nodes:
        3 and 2
    */

    Node* root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "Before Recovery: ";
    inorderTraversal(root);
    cout << endl;

    recoverTree(root);

    cout << "After Recovery : ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}