#include <bits/stdc++.h>
using namespace std;
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
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
    DFS Traversal

    Store:
    key   = column
    value = {row, node_value}
*/
void helper(Node* root,
            int row,
            int col,
            map<int, vector<pair<int, int>>>& mapp) {

    if (root == nullptr)
        return;

    mapp[col].push_back({row, root->data});

    helper(root->left, row + 1, col - 1, mapp);
    helper(root->right, row + 1, col + 1, mapp);
}

/*
    Function: verticalTraversal

    Time Complexity: O(n log n)
    - DFS visits all nodes.
    - Sorting nodes inside columns contributes O(n log n).

    Space Complexity: O(n)
    - Map stores all nodes.
    - Recursive stack up to tree height.
*/
vector<vector<int>> verticalTraversal(Node* root) {

    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    // column -> {row, value}
    map<int, vector<pair<int, int>>> mapp;

    helper(root, 0, 0, mapp);

    for (auto& it : mapp) {

        auto& vec = it.second;

        // Sort by row first, then value
        sort(vec.begin(), vec.end());

        vector<int> curr;

        for (auto& p : vec) {
            curr.push_back(p.second);
        }

        ans.push_back(curr);
    }

    return ans;
}

int main() {

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

        Vertical Traversal:
        [4]
        [2]
        [1,5,6]
        [3]
        [7]
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto& col : ans) {
        cout << "[ ";
        for (int val : col) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}