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
    Function: Paths (Root to Leaf Paths)

    Time Complexity: O(n * h)
    - Every node is visited once.
    - Copying each root-to-leaf path into the answer
      may take O(h) time.
    - h = height of the tree.

    Space Complexity: O(h)
    - Recursion stack.
    - Current path vector.
    - Excluding output space.
*/

void helper(Node* root,
            vector<vector<int>>& ans,
            vector<int>& curr) {

    if (root == nullptr)
        return;

    // Add current node to path
    curr.push_back(root->data);

    // Leaf node reached
    if (root->left == nullptr &&
        root->right == nullptr) {

        ans.push_back(curr);
    }

    helper(root->left, ans, curr);
    helper(root->right, ans, curr);

    // Backtrack
    curr.pop_back();
}

vector<vector<int>> Paths(Node* root) {

    vector<vector<int>> ans;
    vector<int> curr;

    helper(root, ans, curr);

    return ans;
}

int main() {

    /*
                1
              /   \
             2     3
            / \     \
           4   5     6

        Root to Leaf Paths:
        1 2 4
        1 2 5
        1 3 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    vector<vector<int>> ans = Paths(root);

    cout << "Root to Leaf Paths:" << endl;

    for (auto& path : ans) {

        for (int node : path)
            cout << node << " ";

        cout << endl;
    }

    return 0;
}