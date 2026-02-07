#include <bits/stdc++.h>
using namespace std;

int main(){
    
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4); // 1 2 4

    q.back() += 5; // 1 2 9

    cout << q.front() << endl;
    q.pop(); // 2 9

    cout << q.front() << endl;
    cout << q.back() << endl;

    // size swap and empty same as stack
    return 0;
}