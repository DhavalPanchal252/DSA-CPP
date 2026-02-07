#include <bits/stdc++.h>
using namespace std;
//  TC : O(n) , SC : O(1)
int optimal(string s){

    int i=0 ;
    long digit = 0 ;

    while(i<s.size() && s[i] == ' ') i++;
    
    if(i == s.size()) return 0 ;

    int sign = 1 ;
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    else if(s[i] == '+') i++;

    while(i<s.size() && isdigit(s[i])){

        digit = digit*10 + (s[i] - '0');

        if(sign*digit > INT_MAX) return INT_MAX;
        if(sign*digit < INT_MIN) return INT_MIN;

        i++;
    }    

    return (int)(sign*digit);
}

int main(){
    
    string s;
    cin >> s; 

    cout << optimal(s);
}