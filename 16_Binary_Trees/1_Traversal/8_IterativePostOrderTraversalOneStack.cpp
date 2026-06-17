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

    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {

        if (curr) {

            st.push(curr);
            curr = curr->left;
        }
        else {

            Node* temp = st.top()->right;

            // No right subtree
            if (temp == nullptr) {

                temp = st.top();
                st.pop();

                ans.push_back(temp->data);

                // Backtrack while right subtree is already processed
                while (!st.empty() && temp == st.top()->right) {

                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
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