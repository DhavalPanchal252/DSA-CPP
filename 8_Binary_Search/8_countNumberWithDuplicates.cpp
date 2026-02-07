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
    if(first == -1 && last == -1 ) return 0; // means no element found
    
    return last-first+1;
    
}

int optimal(vector<int> &a , int n , int key){// TC : O(logn) , SC : O(1)

    int first = lower_bound(a.begin(),a.end(),key) - a.begin();
    int last = upper_bound(a.begin(),a.end(),key) - a.begin() - 1;

    if(first == n || a[first] != key){
        return 0;
    }

    return last - first+1;
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