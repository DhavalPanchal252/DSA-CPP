#include <bits/stdc++.h>
using namespace std;

// TC : O(n) , SC : O(n)
string better(string s){

    stringstream ss(s);
    vector<string> words;
    string word;

    while(ss >> word){
        words.push_back(word);
    }

    reverse(words.begin(),words.end());

    string str = "";
    int n = words.size();
    for(int i=0 ; i<n ; i++){
        str += words[i];
        if(i != n-1) str += " ";
    }

    return str;
}

// TC : O(n) , SC : O(1)
string optimal(string s){

    reverse(s.begin(),s.end());

    int inx = 0 ;
    int n = s.size();

    for(int i=0 ; i<n ; i++){
        if(s[i] != ' '){

            if(inx != 0) s[inx++] = ' ';

            int j=i ; 

            while(j<n && s[j] != ' ') j++;

            reverse(s.begin()+i , s.begin()+j);

            while(i < j ) s[inx++] = s[i++];
        }
    }
    s.resize(inx);
    return s;
}
int main(){
    
    string s ;
    getline(cin,s);
    
    // string result = better(s);
    string result = optimal(s);

    for(auto &i :result) cout << i;
    return 0;
}