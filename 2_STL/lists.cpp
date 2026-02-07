#include <bits/stdc++.h>
using namespace std;

int main(){
    
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(5);

    for(auto it : ls){
        cout << it << " ";
    }
    return 0;

    //rest of functions like insert,size,swap,begin,end,rbegin,rend are same as the vector
}