#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC = O(n)
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
                
// Function to check if the tree satisfies Children Sum Property
bool checkSumProperty(Node* root) {
    if (!root || (!root->left && !root->right)) 
        return true; // leaf node or empty tree

    int leftVal = root->left ? root->left->data : 0;
    int rightVal = root->right ? root->right->data : 0;

    // Check current node + recursively check children
    return (root->data == leftVal + rightVal) &&
           checkSumProperty(root->left) &&
           checkSumProperty(root->right);
}

// Build tree from level-order input
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < int(arr.size())) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < int(arr.size()) && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildTree(arr);

    if (checkSumProperty(root)) cout << "True";
    else cout << "False";

    return 0;
}