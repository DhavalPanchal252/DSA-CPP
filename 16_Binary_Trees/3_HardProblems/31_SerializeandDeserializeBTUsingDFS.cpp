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
    (DFS - Preorder Traversal)

    Time Complexity:
    Serialize   -> O(n)
    Deserialize -> O(n)

    Space Complexity:
    Serialize   -> O(h)
    Deserialize -> O(h)

    h = height of tree
*/

class Codec {
public:

    // ---------- SERIALIZE ----------

    void serializeHelper(Node* root, string &s) {

        if (root == nullptr) {
            s += "# ";
            return;
        }

        s += to_string(root->data) + " ";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(Node* root) {

        string s = "";

        serializeHelper(root, s);

        return s;
    }

    // ---------- DESERIALIZE ----------

    Node* deserializeHelper(stringstream &ss) {

        string val;
        ss >> val;

        if (val == "#")
            return nullptr;

        Node* root = new Node(stoi(val));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    Node* deserialize(string data) {

        stringstream ss(data);

        return deserializeHelper(ss);
    }
};

// Preorder Traversal for Verification
void preorder(Node* root) {

    if (root == nullptr)
        return;

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
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

    cout << "\nPreorder Traversal After Deserialization:\n";
    preorder(newRoot);

    return 0;
}