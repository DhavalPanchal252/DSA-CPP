#include <bits/stdc++.h>
using namespace std;

//  TC : O(n^2) , SC : O(1)
bool bruteForce(string s , string goal){

    if(s.size() != goal.size()) return false;

    for(int i=0 ; i<s.size() ; i++){ // n

        string rotated = s.substr(i) + s.substr(0,i); // n

        if(rotated == goal) return true;
    }
    return false;
}

//  TC : O(n) , SC : O(n)
bool optimal(string s , string goal){

    if(s.size() != goal.size()) return false;

    string newS = s+s ;
    
    int pos = newS.find(goal);

    if(pos >= 0) return true;
    else return false;
}

int main(){
    
    string s,goal;
    cin >> s;
    cin >> goal;

    // cout << bruteForce(s,goal);
    cout << optimal(s,goal);
    return 0;
}