#include <bits/stdc++.h>
using namespace std;

int main(){
    // take input from the user
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    // Pre-compute

    int hash[13]={0}; // hash size = 13(0 to 12) bcz largest query take by the user will be 12

    for(int i=0;i<n;i++){
        hash[a[i]]+=1;
    }


    //fetch queries

    int q;
    cin >>q; // total number of queries

    while(q!=0){

        int num;
        cin >>num;  // take input for queries

        cout << hash[num] << endl;
        q--;
    }
    return 0;
}