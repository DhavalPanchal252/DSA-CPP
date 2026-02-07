#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);  
    s.push(2);   
    s.push(3);   
    s.push(3);   
    s.emplace(5);
    // stack doesnt support iterators
    // Print and empty the stack
    stack<int> temp = s; 
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    cout << s.top() << endl;
    
    s.swap(temp);

    cout << s.size() << endl;
    cout << temp.size() << endl;
    cout << s.empty() << endl;

    return 0;
}