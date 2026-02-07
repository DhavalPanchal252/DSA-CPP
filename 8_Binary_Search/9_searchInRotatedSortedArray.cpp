#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)
    
    for(int i = 0 ; i<n ; i++){

        if(a[i] == key ){
            return i;
        }
    }
    
    return -1 ;
    
}

int optimal(vector<int> &a , int n , int key){// TC : O(logn) , SC : O(1)

    int low = 0;
    int high = n-1;

    while(low<=high){
        
        int mid = low + (high-low)/2;
        if(a[mid] == key) return mid;
        // left half is sorted
        else if(a[low] <= a[mid]){
            if(a[low] <= key && key <= a[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // right half is sorted
        else{
            if(a[mid] <= key && key <= a[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
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