#include <bits/stdc++.h>
using namespace std;

int helper(string &s , int i , long long digit , int sign){

    if(i >= s.size() || !isdigit(s[i])) return (int)(digit*sign);

    digit = digit*10 + (s[i] - '0');

    if(digit*sign > INT_MAX) return INT_MAX;
    if(digit*sign < INT_MIN) return INT_MIN;


    return helper(s,i+1,digit,sign);
}

int recursion(string s){
    int i = 0;

    while(i < s.size() && s[i] == ' '){
        i++;
    }

    if(i == s.size()) return 0;

    int sign = 1;

    if(s[i] == '-'){
        sign = -1;
        i++;
    } 
    else if(s[i] == '+') i++;

    return helper(s , i , 0 , sign);
}

int main(){
    
    string s;

    cin >> s;

    cout << recursion(s);
    return 0;
}