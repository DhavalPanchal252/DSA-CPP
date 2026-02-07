#include <bits/stdc++.h>
using namespace std;

int main(){
    // intialization
    vector<int> v ; // {}
    // vector<int> v(5) ; vector size is 5, but after this line i add new element size will dynamically increases
    v.push_back(1); // {1}
    v.emplace_back(2); // {1,2} 
    // emplace_back is faster than push_back
    
    vector<pair<int,int>> vec;

    vec.push_back({10,20}); // {{1,2}}
    vec.emplace_back(30,40); // {{1,2},{3,4}}

    vector<int> v1(5,100); // {100,100,100,100,100}

    vector<int> v2(v1); // vector v1 copy into vector v2

    cout << v[0] << endl;
    cout << v.front() << " " << endl; // gives first element in the vector
    cout << v.back() << " " << endl; // gives last element in the vector
    cout << vec[0].second << endl;
    cout << v1[0] << " " << v1[4] << endl;
    cout << v2[0] << " " << v2[4] << endl;
    return 0;
}