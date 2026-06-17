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

vector<vector<int>> levelOrder(Node* root){

    vector<vector<int>> ans;
    
    if(root == nullptr) return ans;
    
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){

        vector<int> level;

        int size = q.size();

        for(int i=0 ; i<size ; i++){

            Node* node = q.front();
            q.pop();

            level.push_back(node->data);

            if(node->left) q.push(node->left);

            if(node->right) q.push(node->right);
        }

        ans.push_back(level);
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

    vector<vector<int>> ans = levelOrder(root);

    for(auto &i : ans){
        for(auto &j : i){

            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}