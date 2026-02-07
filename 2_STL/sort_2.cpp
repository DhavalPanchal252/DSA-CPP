#include <bits/stdc++.h>
using namespace std;
/*
sort it according to second element, if second element is same then sort it according to first element but in descending order
*/
bool comp(pair<int ,int> p1 ,pair<int ,int> p2)
{
    if(p1.second<p2.second) return true; // no need to swap
    if(p1.second>p2.second) return false; //  need to swap , swap by sort function internally

    // only one option are left : thry both are same

    if(p1.first>p2.first) return true;
    else return false; // swap
}

int main(){
    int n=3;
    pair<int,int> a[] = {{1,2},{2,1},{4,1}};

    sort(a , a+n , comp);

    for ( auto it : a){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
