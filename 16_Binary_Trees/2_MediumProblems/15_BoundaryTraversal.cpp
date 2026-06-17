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
    Function: boundaryTraversal

    Time Complexity: O(n)
    - Left boundary traversal: O(h)
    - Leaf nodes traversal: O(n)
    - Right boundary traversal: O(h)
    - Overall: O(n)

    Space Complexity: O(h)
    - Recursion stack during leaf traversal.
    - Stack used for storing right boundary nodes.
    - h = height of the tree.
*/

class Solution {
public:

    // Check whether a node is a leaf node
    bool isLeaf(Node* node) {
        return (!node->left && !node->right);
    }

    // Add left boundary excluding leaf nodes
    void addLeft(Node* root, vector<int>& ans) {

        Node* curr = root->left;

        while (curr) {

            if (!isLeaf(curr))
                ans.push_back(curr->data);

            // Prefer left child, otherwise move right
            curr = curr->left ? curr->left : curr->right;
        }
    }

    // Add all leaf nodes using DFS
    void addLeaf(Node* root, vector<int>& ans) {

        if (root == nullptr)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaf(root->left, ans);
        addLeaf(root->right, ans);
    }

    // Add right boundary in reverse order excluding leaf nodes
    void addRight(Node* root, vector<int>& ans) {

        Node* curr = root->right;

        stack<int> st;

        while (curr) {

            if (!isLeaf(curr))
                st.push(curr->data);

            // Prefer right child, otherwise move left
            curr = curr->right ? curr->right : curr->left;
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }

    vector<int> boundaryTraversal(Node* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        // Add root only if it is not a leaf
        if (!isLeaf(root))
            ans.push_back(root->data);

        addLeft(root, ans);
        addLeaf(root, ans);
        addRight(root, ans);

        return ans;
    }
};

int main() {

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

        Boundary Traversal:
        1 2 4 5 6 7 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;

    vector<int> ans = obj.boundaryTraversal(root);

    cout << "Boundary Traversal: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}