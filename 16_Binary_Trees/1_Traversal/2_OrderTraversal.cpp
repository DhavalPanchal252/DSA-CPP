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

// Inorder 
void inorder(Node* root, vector<int>& ans) {

    if (root == nullptr) return;

    inorder(root->left, ans);

    ans.push_back(root->data);

    inorder(root->right, ans);
}

vector<int> inorderTraversal(Node* root) {

    vector<int> ans;

    inorder(root, ans);

    return ans;
}

// preorder 
void preorder(Node* root, vector<int>& ans) {

    if (root == nullptr) return;

    ans.push_back(root->data);

    preorder(root->left, ans);
    preorder(root->right, ans);
}

vector<int> preorderTraversal(Node* root) {

    vector<int> ans;

    preorder(root, ans);

    return ans;
}

// postorder 
void postorder(Node* root, vector<int>& ans) {

    if (root == nullptr) return;

    postorder(root->left, ans);

    postorder(root->right, ans);
    
    ans.push_back(root->data);
}

vector<int> postorderTraversal(Node* root) {

    vector<int> ans;

    postorder(root, ans);

    return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    vector<int> inorder = inorderTraversal(root);
    vector<int> preorder = preorderTraversal(root);
    vector<int> postorder = postorderTraversal(root);

    cout << "In order : ";
    for (int x : inorder) {
        cout << x << " ";
    }

    cout << endl;
    cout << "Pre order : ";
    for (int x : preorder) {
        cout << x << " ";
    }

    cout << endl;
    cout << "Post order : ";
    for (int x : postorder) {
        cout << x << " ";
    }

    return 0;
}