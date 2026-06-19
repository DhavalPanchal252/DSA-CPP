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

/*
    Serialize & Deserialize Binary Tree
    (BFS / Level Order Traversal)

    Time Complexity:
    Serialize   -> O(n)
    Deserialize -> O(n)

    Space Complexity:
    Serialize   -> O(n)
    Deserialize -> O(n)
*/

class Codec {
public:

    // Serialize Tree
    string serialize(Node* root) {

        if (root == nullptr)
            return "";

        string data = "";

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                data += "#,";
            }
            else {

                data += to_string(curr->data) + ",";

                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return data;
    }

    // Deserialize Tree
    Node* deserialize(string data) {

        if (data.size() == 0)
            return nullptr;

        stringstream ss(data);

        string str;

        getline(ss, str, ',');

        Node* root = new Node(stoi(str));

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            Node* node = q.front();
            q.pop();

            // Left Child
            getline(ss, str, ',');

            if (str == "#") {
                node->left = nullptr;
            }
            else {

                Node* leftNode = new Node(stoi(str));

                node->left = leftNode;
                q.push(leftNode);
            }

            // Right Child
            getline(ss, str, ',');

            if (str == "#") {
                node->right = nullptr;
            }
            else {

                Node* rightNode = new Node(stoi(str));

                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Level Order Traversal for Verification
void levelOrder(Node* root) {

    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

int main() {

    /*
                1
              /   \
             2     3
                  / \
                 4   5
    */

    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Codec codec;

    // Serialize
    string serializedTree = codec.serialize(root);

    cout << "Serialized Tree:\n";
    cout << serializedTree << endl;

    // Deserialize
    Node* newRoot = codec.deserialize(serializedTree);

    cout << "\nLevel Order Traversal After Deserialization:\n";
    levelOrder(newRoot);

    return 0;
}