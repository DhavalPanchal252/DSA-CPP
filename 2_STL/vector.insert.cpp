#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v(2,100); // {100,100}

    v.insert(v.begin(),300); // {300,100,100,}
    v.insert(v.begin()+1,2,10);//{300,10,10,100,100}

    vector<int> v1(2,50); // {50,50}
    v.insert(v.begin(),v1.begin(),v1.end()); // {50,50,300,10,10,100,100}
   
    cout << v.size() << endl;

    for(auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;

    v.pop_back(); // removes last element : 100
   v.swap(v1);
   
   cout << v.size() << endl;
   cout << v1.size() << endl;

   v.clear(); // erases the entire vector

   cout << v.empty(); // 1:true and 0:false
   return 0;
}