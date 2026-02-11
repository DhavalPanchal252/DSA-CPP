#include <bits/stdc++.h>
using namespace std;
// Assume DLL is sorted
class Node{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int data1 , Node* prev1 , Node* next1){
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

Node* convertArrToDLL(vector<int> &arr , int n){

    if(n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i=1 ; i<n ; i++){
        Node* temp = new Node(arr[i] , back , nullptr);
        back->next = temp;
        back = back->next;
    }
    return head;
}

// TC : O(n) , SC : O(1)
vector<pair<int,int>> optimal(Node* head , int target){

    vector<pair<int,int>> ans;
    
    if(!head) return ans;

    Node* temp = head;
    
    Node* left = head;
    Node* right = head;
    
    while(right->next){
        right = right->next;
    }


    while(left &&  right && right->next != left && left != right){

        int sum = left->data + right->data;

        if(sum == target){
            ans.push_back({left->data , right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum > target){
            right = right->prev;
        }
        else left = left->next;
    }
    return ans;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    // insert elemetns in sorted order
    for(auto &i : arr) cin >> i;

    int target;
    cin >> target;

    Node* node = convertArrToDLL(arr,n);

    vector<pair<int,int>> ans = optimal(node,target);

    for(auto &i : ans) cout << i.first <<"," << i.second << endl;
    return 0;
}