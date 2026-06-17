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


vector<int> inorder(Node* root){

    vector<int> ans;

    if(root == nullptr) return ans;

    stack<Node*> st;
    
    Node* node = root;

    while(node || !st.empty()){

        while(node){
            st.push(node);
            node = node->left;
        }

        node = st.top();
        st.pop();

        ans.push_back(node->data);

        node = node->right;
    }

    return ans;
}

int main() {
    // Creating a sample tree for testing:
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

    vector<int> ans = inorder(root);

    for(auto &i : ans) cout << i << " ";

    return 0;
}