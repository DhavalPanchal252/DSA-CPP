#include <bits/stdc++.h>
using namespace std;
// Retriving element from vector

int main(){
    vector<int> v = {1,2,3,4,5};
    
// for(vector<int> :: iterator it = v.begin() ; it != v.end() ; it++){}
    
    for(auto it = v.begin() ; it != v.end() ; it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;
    
// for each loop 
    for(auto it : v)
    {
        cout << it << " ";
    }
    
    return 0;
}