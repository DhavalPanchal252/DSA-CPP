#include <bits/stdc++.h>
using namespace std;

bool palin(string &s){
    string rev =s; // use duplicate string bcz s is assigned to given input
    reverse(rev.begin(),rev.end());
    return rev == s;
}

int main(){

string s;
cin >> s;

if(palin(s)) cout << "Palindrome";
else cout << "Not Palindrome";
    return 0;
}