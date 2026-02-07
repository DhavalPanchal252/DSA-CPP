#include <bits/stdc++.h>
using namespace std;

int main(){
    // take input from the user
    string a;
    getline(cin,a);

    // Pre-compute

    // int hash[26]={0};// for both lower case and upper case 
    int hash[256]={0};// for both lower case and upper case 

    for(int i=0;i<a.size();i++){
        // hash[a[i]-'a']+=1;// only if lower case
        hash[a[i]]+=1;// only if lower case
    }

    //fetch queries

    int q;
    cin >>q; // total number of queries

    while(q!=0){

        char c;
        cin >>c;  // take input for queries

        // cout << hash[c-'a'] << endl;// only if lower case
        cout << hash[c] << endl;// for both lower case and upper case
        q--;
    }
    return 0;
}