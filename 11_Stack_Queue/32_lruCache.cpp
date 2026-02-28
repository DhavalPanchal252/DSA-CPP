#include <bits/stdc++.h>
using namespace std;

class Node{
public:

    int key;
    int value;
    int cnt;
    Node* prev;
    Node* next;

    Node(int key1,int value1){
        key = key1;
        value = value1;
        prev = nullptr;
        cnt = 1;
        next = nullptr;
    }
};

class LRUCache {
public:
    
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mapp;
    int capacity;

    void insertAfterHead(Node* newNode){
        Node* currNext = head->next;
        head->next = newNode;
        currNext->prev = newNode;
        newNode->prev = head;
        newNode->next = currNext;
    }

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    LRUCache(int capacity1) {
        capacity = capacity1;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mapp.find(key) == mapp.end())
            return -1;

        Node* node = mapp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int val) {
        if(mapp.find(key) != mapp.end()){
            Node* node = mapp[key];
            node->value = val;
            deleteNode(node);
            insertAfterHead(node);
        } 
        else{
            if(mapp.size() == capacity){
                
                Node* node = tail->prev;
                mapp.erase(node->key);
                deleteNode(node);
                delete node;
                
            }
            Node* node = new Node(key,val);
            mapp[key] = node;
            insertAfterHead(node);
        }
    }
};

int main(){
    
    LRUCache* obj = new LRUCache(2);

    obj->put(1,10);
    obj->put(2,20);

    cout << obj->get(1) << endl;

    obj->put(3,30);

    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;

    return 0;
}