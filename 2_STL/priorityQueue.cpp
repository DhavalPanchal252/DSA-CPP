#include <bits/stdc++.h>
using namespace std;

int main(){
    // Largest element at top : Max Heap
    priority_queue<int> q;
    q.push(5); // 5
    q.push(2); // 5 2
    q.push(8); // 8 5 2 
    q.emplace(10); // 10 8 5 2

    cout << q.top() << endl; // 10
    
    q.pop();

    cout << q.top() << endl; // 8
    
    // Minimum element at top : Min Heap
    priority_queue<int, vector<int>,greater<int>> mq;
    mq.push(5); // 5
    mq.push(2); // 2 5
    mq.push(8); // 2 5 8 
    mq.emplace(10); // 2 5 8 10
    
    cout << mq.top() << endl; // 2
    
    mq.pop();

    cout << mq.top() << endl; // 5
    // size swap and empty same as stack
    
    return 0;
}