#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4,10,50};

    if(binary_search(a.begin(),a.end(),30)){
         cout << "yes";
        }
    else {
        cout << "no";
    }
    return 0;
}