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

vector<vector<int>> preInPostTraversal(Node* root) {

    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    if (root == nullptr)
        return {preorder, inorder, postorder};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {

        auto it = st.top();
        st.pop();

        // 1 : preorder
        if (it.second == 1) {
            
            // print
            preorder.push_back(it.first->data);

            // 2
            it.second++;
            st.push(it);

            // check left then push left
            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        // 2 : pre order
        else if (it.second == 2) {

            // print
            inorder.push_back(it.first->data);

            // 3 
            it.second++;
            st.push(it);

            // check right then push right
            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        }

        else {
            // no need to push again node
            postorder.push_back(it.first->data);
        }
    }

    return {preorder, inorder, postorder};
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    vector<vector<int>> traversal = preInPostTraversal(root);

    vector<int> preorder = traversal[0];
    vector<int> inorder = traversal[1];
    vector<int> postorder = traversal[2];

    cout << "Inorder: ";
    for (int x : inorder)
        cout << x << " ";

    cout << "\nPreorder: ";
    for (int x : preorder)
        cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : postorder)
        cout << x << " ";

    return 0;
}