#include <bits/stdc++.h>
using namespace std;

int iterative(vector<int> &a , int n , int key){ // TC : O(logn) , SC : O(1)

    int i = 0 ;
    int j = n-1;

    while(i<=j){
        int mid = (i+j)/2;

        if(a[mid] == key) return mid;
        else if(a[mid] < key) i = mid+1;
        else j = mid-1; 
    }
    return -1;
}

int recursive(vector<int> &a ,int i , int j , int key){ // TC : O(logn) , SC : O(1)

    if(i>j) return -1;

    int mid = i + (j-i)/2;

    if(a[mid] == key) 
        return mid;
    else if(a[mid] < key) 
        return recursive(a,mid+1,j,key);
    else  
        return recursive(a,i,mid-1,key);
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int key;
    cin >> key;

    // cout << iterative(a,n,key);
    cout << recursive(a,0,n-1,key);
    
    return 0;
}