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
    Function: inorderTraversal

    Morris Inorder Traversal

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
          Create thread and move left.

       b) If predecessor->right points to current:
          Remove thread, visit current,
          and move right.
*/

vector<int> inorderTraversal(Node* root) {

    vector<int> inorder;

    Node* curr = root;

    while (curr) {

        // No left subtree
        if (!curr->left) {

            inorder.push_back(curr->data);

            curr = curr->right;
        }
        else {

            // Find inorder predecessor
            Node* prev = curr->left;

            while (prev->right && prev->right != curr) prev = prev->right;
            
            // Create thread
            if (!prev->right) {

                prev->right = curr;

                curr = curr->left;
            }
            // Thread already exists
            else {

                prev->right = nullptr;

                inorder.push_back(curr->data);

                curr = curr->right;
            }
        }
    }

    return inorder;
}

int main() {

    /*
                1
                 \
                  2
                 /
                3

        Inorder:
        1 3 2
    */

    Node* root = new Node(1);

    root->right = new Node(2);
    root->right->left = new Node(3);

    vector<int> ans = inorderTraversal(root);

    cout << "Morris Inorder Traversal: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}