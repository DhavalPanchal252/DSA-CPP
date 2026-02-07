// LCA : first intersection point at last from bottom
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Find LCA in BST
int LCA(Node* root, int p, int q) {
    while (root != nullptr) {
        if (p < root->data && q < root->data) {
            root = root->left; 
        } 
        else if (p > root->data && q > root->data) {
            root = root->right; 
        } 
        else {
            return root->data; 
        }
    }
    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int p, q;
    cin >> p >> q;

    Node* root = nullptr;
    for (int x : arr) {
        root = insert(root, x);
    }

    cout << LCA(root, p, q) << "\n";
    return 0;
}
