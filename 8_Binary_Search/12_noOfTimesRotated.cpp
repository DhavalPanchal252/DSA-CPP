#include <bits/stdc++.h>
using namespace std;
// same as finding minimum
int bruteForce(vector<int> &a , int n){ // TC : O(n) , SC : O(1)
    
    int minimum = INT_MAX;
    int index;
    for(int i = 0 ; i<n ; i++){

        if(a[i]<=minimum){
            minimum = a[i];
            index = i;
        }
    }
    return index ;
}


int optimal(vector<int> &a , int n){// TC : O(logn) , SC : O(1)

    int low = 0;
    int high = n-1;
    int minimum = INT_MAX;
    int index;

    while(low<=high){
        
        int mid = low + (high-low)/2;

        // this only happens when discard all rotated elements from left... then we have remains only sorted array so just take low element as minimum
        if(a[low] <= a[high]){
            minimum = min(minimum, a[low]);
            index = low;
            break;
        }

        // left half is sorted
        if(a[low]<=a[mid]){
            minimum = min(minimum, a[low]);
            index = low;
            low = mid+1; // after finding minimum in sorted array just discard and find check in other half
        }
        // right half is sorted
        else{
            minimum = min(minimum,a[mid]);
            index = mid;
            high = mid-1;// after finding minimum in sorted array just discard and find check in other half
        }
    }
    return index;
}
int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    // cout << bruteForce(a,n);
    cout << optimal(a,n);

    return 0;
}



