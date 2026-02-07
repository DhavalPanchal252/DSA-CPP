#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {10,20,30,40};
    
    vector<int> :: iterator it = v.begin(); // "it" points to first memory location of element
    // auto it = v.begin(); short form

    it++; // increment by memory location , not actual element 
    // so , now "it" points to 2nd element mem address
    cout << *(it) << " "; // just like pointers in C lang.

    it+=2; // now "it" points to 4th element mem address 
    cout << *(it) << " ";
    return 0;
}