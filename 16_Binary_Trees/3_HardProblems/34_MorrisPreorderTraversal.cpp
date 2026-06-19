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
    Function: preorderTraversal

    Morris Preorder Traversal

    Time Complexity: O(n)
    - Every node is visited at most twice.

    Space Complexity: O(1)
    - No recursion stack.
    - No explicit stack.

    Idea:
    1. If left child is NULL:
       Visit current node and move right.

    2. Otherwise:
       Find inorder predecessor.

       a) If predecessor->right is NULL:
          Visit current node.
          Create thread.
          Move left.

       b) If predecessor->right points to current:
          Remove thread.
          Move right.
*/

vector<int> preorderTraversal(Node* root) {

    vector<int> preorder;

    Node* curr = root;

    while (curr) {

        // No left subtree
        if (!curr->left) {

            preorder.push_back(curr->data);

            curr = curr->right;
        }
        else {

            // Find inorder predecessor
            Node* prev = curr->left;

            while (prev->right && prev->right != curr) prev = prev->right;
            
            // Create thread
            if (!prev->right) {

                preorder.push_back(curr->data);

                prev->right = curr;

                curr = curr->left;
            }
            // Thread already exists
            else {

                prev->right = nullptr;

                curr = curr->right;
            }
        }
    }

    return preorder;
}

int main() {

    /*
                1
               / \
              2   3
             / \
            4   5

        Preorder:
        1 2 4 5 3
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = preorderTraversal(root);

    cout << "Morris Preorder Traversal: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}