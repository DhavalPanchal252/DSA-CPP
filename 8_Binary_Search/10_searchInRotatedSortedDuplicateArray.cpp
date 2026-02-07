#include <bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)
    
    for(int i = 0 ; i<n ; i++){

        if(a[i] == key ){
            return true;
        }
    }
    
    return false ;
    
}

int optimal(vector<int> &a , int n , int key){// TC : O(logn) , SC : O(1)

    int low = 0;
    int high = n-1;
    int minimum = INT_MAX;

    while(low<=high){
        
        int mid = low + (high-low)/2;

        if(a[mid] <= minimum){
            minimum = a[mid];
        } 
        // this need to check bcz , this condition is true then we cant able to decide which half is sorted
        if(a[low] == a[mid] && a[mid] == a[high]){
            low++;
            high--;
            continue;
        }
        // left half is sorted
        else if(a[low] <= a[mid]){
            if(a[low] <= minimum && minimum <= a[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // right half is sorted
        else{
            if(a[mid] <= minimum && minimum <= a[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return minimum;
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int key;
    cin >> key;

    // cout << bruteForce(a,n,key);
    cout << optimal(a,n);
    
    return 0;
}