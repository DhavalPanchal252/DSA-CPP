#include <bits/stdc++.h>
using namespace std;
/*Unlike vector (fast at back) and list (fast at both but uses more memory), deque gives you the best of both worlds with random access + fast front/back insert/delete.*/
int main(){

    deque<int> q;

    q.push_back(7);
    q.emplace_back(4);
    q.emplace_front(2);
    q.push_front(5);
    
    for(auto it : q){
        cout << it << " ";
    }
    cout << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    
    for(auto it : q){
        cout << it << " ";
    }
    
    return 0;
    //rest of functions like insert,size,swap,begin,end,rbegin,rend are same as the vector
}