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

/*=========================================================
    METHOD 1 : Reverse Preorder (Recursion)

    Time Complexity: O(n)
    Space Complexity: O(h)

    Idea:
    Right -> Left -> Root

    Keep a 'prev' pointer.
    Connect current node to prev.
=========================================================*/

void helper(Node* root, Node* &prev) {

    if (root == nullptr)
        return;

    helper(root->right, prev);
    helper(root->left, prev);

    root->right = prev;
    root->left = nullptr;

    prev = root;
}

void flattenRecursive(Node* root) {

    Node* prev = nullptr;

    helper(root, prev);
}

/*=========================================================
    METHOD 2 : Morris Traversal

    Time Complexity: O(n)
    Space Complexity: O(1)

    Idea:
    For every node having left subtree:
    1. Find rightmost node of left subtree.
    2. Connect it to current's right subtree.
    3. Move left subtree to right.
    4. Set left = NULL.
=========================================================*/

void flattenMorris(Node* root) {

    Node* curr = root;

    // Iterate until 'curr'
    // becomes NULL
    while (curr) {
        // Check if the current
        // node has a left child
        if (curr->left) {
            // If yes, find the rightmost
            // node in the left subtree
            Node* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }

            // Connect the rightmost node in
            // the left subtree to the current
            //  node's right child
            pre->right = curr->right;

            // Move the entire left subtree to the
            // right child of the current node
            curr->right = curr->left;

            // Set the left child of
            // the current node to NULL
            curr->left = NULL;
        }

        // Move to the next node
        // on the right side
        curr = curr->right;
    }
}

/* Print Flattened Tree */
void printFlattened(Node* root) {

    while (root) {

        cout << root->data << " ";

        root = root->right;
    }

    cout << endl;
}

int main() {

    /*
                1
              /   \
             2     5
            / \     \
           3   4     6

        Flattened:
        1 -> 2 -> 3 -> 4 -> 5 -> 6
    */

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(5);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->right = new Node(6);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(5);
    root2->left->left = new Node(3);
    root2->left->right = new Node(4);
    root2->right->right = new Node(6);

    // Method 1
    flattenRecursive(root1);

    cout << "Flatten using Recursive Method:\n";
    printFlattened(root1);

    // Method 2
    flattenMorris(root2);

    cout << "\nFlatten using Morris Method:\n";
    printFlattened(root2);

    return 0;
}