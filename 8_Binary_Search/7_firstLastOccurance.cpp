#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)

    int first = -1 , last = -1 ;
    
    for(int i = 0 ; i<n ; i++){

        if(a[i] == key ){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    return first;
    // return last;
}

int optimal(vector<int> &a , int n , int key){

    int first = lower_bound(a.begin(),a.end(),key) - a.begin();
    int last = upper_bound(a.begin(),a.end(),key) - a.begin() - 1;

    if(first == n || a[first] != key){
        first = -1 ;
        last = -1 ;
    }

    return first;
    // return last;
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int key;
    cin >> key;

    // cout << bruteForce(a,n,key);
    cout << optimal(a,n,key);
    
    return 0;
}