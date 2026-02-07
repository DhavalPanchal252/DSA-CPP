#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {10,20,30,40};
    
    vector<int> :: iterator it = v.end(); // "it" points to the next address of the last element
    // auto it = v.end(); short form
    
    it--; //  so , now "it" points to last element mem address
    cout << *(it) << " "; 

    it-=2; // now "it" points to 2nd element mem address 
    cout << *(it) << " ";
    return 0;
}