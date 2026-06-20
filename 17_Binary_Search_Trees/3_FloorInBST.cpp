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
    Function: findMaxFork

    Finds the Floor of K in a BST.

    Floor:
    Largest value <= K

    Time Complexity: O(h)
    - Traverse one path in BST.

    Space Complexity: O(1)

    h = Height of BST
*/

int findMaxFork(Node* root, int k) {

    int floorValue = -1;

    while (root) {

        // Exact match found
        if (root->data == k) {
            floorValue = root->data;
            return floorValue;
        }

        // Move left
        if (k < root->data) {
            root = root->left;
        }
        else {
            // Possible floor
            floorValue = root->data;
            root = root->right;
        }
    }

    return floorValue;
}

int main() {

    /*
                8
              /   \
             4     12
            / \    / \
           2   6  10 14

        K = 11

        Floor = 10
    */

    Node* root = new Node(8);

    root->left = new Node(4);
    root->right = new Node(12);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int k = 11;

    cout << "Floor of " << k << " = "
         << findMaxFork(root, k);

    return 0;
}