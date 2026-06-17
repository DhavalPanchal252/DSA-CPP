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

vector<int> postorder(Node* root) {

    vector<int> ans;

    if (root == nullptr) return ans;

    // stack 1 : root , right , left 
    // stack 2 : reverse of stack1 so ans : left , right , root => post order
    stack<Node*> st1, st2;

    st1.push(root);

    while (!st1.empty()) {

        Node* node = st1.top();
        st1.pop();

        st2.push(node);

        if (node->left)
            st1.push(node->left);

        if (node->right)
            st1.push(node->right);
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->data);
        st2.pop();
    }

    return ans;
}

int main() {

    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = postorder(root);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}