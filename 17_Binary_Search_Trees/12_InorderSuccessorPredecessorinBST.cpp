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
    Predecessor and Successor in BST

    Predecessor:
    Largest value smaller than key

    Successor:
    Smallest value greater than key

    TC: O(h)
    SC: O(1)
==================================================
*/

vector<int> succPredBST(Node* root, int key) {

    int predecessor = -1;
    int successor = -1;

    while (root) {

        if (root->data < key) {

            predecessor = root->data;
            root = root->right;
        }
        else if (root->data > key) {

            successor = root->data;
            root = root->left;
        }
        else {

            // Find predecessor
            if (root->left) {

                Node* curr = root->left;

                while (curr->right)
                    curr = curr->right;

                predecessor = curr->data;
            }

            // Find successor
            if (root->right) {

                Node* curr = root->right;

                while (curr->left)
                    curr = curr->left;

                successor = curr->data;
            }

            break;
        }
    }

    return {predecessor, successor};
}

int main() {

    /*
                8
              /   \
             5     10
            / \      \
           1   7      12

        Key = 8

        Predecessor = 7
        Successor   = 10
    */

    Node* root = new Node(8);

    root->left = new Node(5);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(7);

    root->right->right = new Node(12);

    int key = 8;

    vector<int> ans = succPredBST(root, key);

    cout << "Predecessor = " << ans[0] << endl;
    cout << "Successor   = " << ans[1] << endl;

    return 0;
}