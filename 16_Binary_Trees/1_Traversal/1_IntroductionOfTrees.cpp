#include <bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* createBinaryTree(){

    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);

    root->right->left = new Node(4);

    return root;


}
int main(){
    
    Node* root = createBinaryTree();

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    cout << root->right->left->data << endl;
    
    return 0;
}