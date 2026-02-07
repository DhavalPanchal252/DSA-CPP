#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4};

    v.erase(v.begin()+1); // erase 2nd element

    for( auto it : v)
    {
        cout << it << " "; // 1 3 4
    }
    cout << endl;
    
    vector<int> v1 = {1,2,3,4,5,6};
    // erase[start, end)
    v1.erase(v1.begin()+1,v1.begin()+4); // erase 2nd element to 4th element , ust like slicing in python

    for( auto it : v1)
    {
        cout << it << " "; // 1 5 6
    }
    return 0;
}