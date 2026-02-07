#include <bits/stdc++.h>
using namespace std;

//  TC : O(n) , SC : O(1)
int optimal(string &s){

    int maxPara = 0 ;
    int para = 0 ;

    for(auto &i : s){
        if(i == '(') para++ ;
        else if(i == ')') para-- ;

        maxPara = max(para,maxPara);
    }
    return maxPara;
}

int main(){
    
    string s;
    cin >> s; 

    cout << optimal(s);
}