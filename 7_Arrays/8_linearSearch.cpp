#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(n), where n is the length of the array.

Space Complexity: O(1)
*/
bool linerS(vector<int> a , int n , int key){

    for(int i = 0 ; i < n ; i++){

        if(a[i] == key) return true;
        else return false;
    }

}

int main(){
    int n;
    cin >> n;   

    vector<int> a(n);
    for(auto &i : a){

        cin >> i;
    }

    int key;
    cin >> key;

    if(linerS(a,n,key)) cout << "key found.";
    else cout << "key Not found.";
    return 0;
}