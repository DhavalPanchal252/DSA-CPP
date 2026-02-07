#include <bits/stdc++.h>
using namespace std;

int main(){
    
    pair<int, int> p = {2,3}; // integer pair

    cout << p.first << endl;
    cout << p.second << endl;

    pair<int , pair<int, int>> q = {5,{8,9}}; //multi pair

    cout << q.first << endl;
    cout << q.second.first << endl;

    pair<char , int> c = {'d',0}; // int and char combine pair
    cout << c.first << endl;
    cout << c.second << endl;

    pair<int,int> a[] = {{10,20},{30,40},{50,60}}; // Array pair
    cout << a[1].second;
    return 0;
}