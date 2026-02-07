#include <bits/stdc++.h>
using namespace std;

// TC : O(nlogn + m) , SC : O(m)
string optimal(vector<string> &strs , int n){
    string result = "";

    sort(strs.begin(),strs.end()); // nlogn

    for(int i=0 ; i<strs[0].size() ; i++){ // m
        if(strs[0][i] == strs[n-1][i]){
            result.push_back(strs[0][i]);
        }
        else break;
    }
    return result;
}

int main(){
    
    int n;
    cin >> n ;

    vector<string> strs(n);

    for(auto &i : strs) cin >> i ;
    
    string result = optimal(strs , n);

    for(auto &i :result) cout << i;
    return 0;
}