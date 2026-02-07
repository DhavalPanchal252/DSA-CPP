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

// Search in BST
bool search(Node* root, int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    else if (val < root->data) return search(root->left, val);
    else return search(root->right, val);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int val;
    cin >> val;

    Node* root = nullptr;
    for (auto x : arr) {
        root = insert(root, x);
    }

    if (search(root, val)) cout << "true\n";
    else cout << "false\n";

    return 0;
}
