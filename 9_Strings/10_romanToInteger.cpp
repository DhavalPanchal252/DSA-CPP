#include <bits/stdc++.h>
using namespace std;
//  TC : O(n) , SC : O(1)
int optimal(string s){
    unordered_map<char , int> p = {
        {'I' , 1} ,
        {'V' , 5} ,
        {'X' , 10} ,
        {'L' , 50} ,
        {'C' , 100} ,
        {'D' , 500} ,
        {'M' , 1000} 
    };

    int digit = 0;
    for(int i=s.size()-1 ; i>=0 ; i--){

        if ( i>0 && p[s[i]] > p[s[i-1]]){
            digit = digit + p[s[i]] - p[s[i-1]] ;
            i--;
        }
        else{
            digit +=  p[s[i]];
        }
    }
    return digit;
}

int main(){
    
    string s;
    cin >> s; 

    cout << optimal(s);
}