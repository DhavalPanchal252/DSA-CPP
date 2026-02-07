#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &a , int n){ // TC : O(n) , SC : O(1)
    
    int minimum = INT_MAX;
    for(int i = 0 ; i<n ; i++){

        minimum = min(minimum,a[i]);
    }
    return minimum ;
}

int optimal1(vector<int> &a , int n){// TC : O(logn) , SC : O(1)

    int low = 0;
    int high = n-1;
    int minimum = INT_MAX;

    while(low<=high){
        
        int mid = low + (high-low)/2;

        // left half is sorted
        if(a[low]<=a[mid]){
            minimum = min(minimum, a[low]);
            low = mid+1; // after finding minimum in sorted array just discard and find check in other half
        }
        // right half is sorted
        else{
            minimum = min(minimum,a[mid]);
            high = mid-1;// after finding minimum in sorted array just discard and find check in other half
        }
    }
    return minimum;
}

int optimal2(vector<int> &a , int n){// TC : O(logn) , SC : O(1)

    int low = 0;
    int high = n-1;
    int minimum = INT_MAX;

    while(low<=high){
        
        int mid = low + (high-low)/2;

        // this only happens when discard all rotated elements from left... then we have remains only sorted array so just take low element as minimum
        if(a[low] <= a[high]){
            minimum = min(minimum, a[low]);
            break;
        }

        // left half is sorted
        if(a[low]<=a[mid]){
            minimum = min(minimum, a[low]);
            low = mid+1; // after finding minimum in sorted array just discard and find check in other half
        }
        // right half is sorted
        else{
            minimum = min(minimum,a[mid]);
            high = mid-1;// after finding minimum in sorted array just discard and find check in other half
        }
    }
    return minimum;
}

int optimalDuplicated(vector<int> &a, int n) {  
    // TC: O(log n) average, O(n) worst | SC: O(1)

    int low = 0;
    int high = n - 1;
    int minimum = INT_MAX;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        // ⭐ duplicate case: cannot decide which half is sorted
        if (a[low] == a[mid] && a[mid] == a[high]) {
            minimum = min(minimum, a[low]);
            low++;
            high--;
            continue;
        }

        // left half is sorted
        if (a[low] <= a[mid]) {
            minimum = min(minimum, a[low]);
            low = mid + 1;   // discard left half
        }
        // right half is sorted
        else {
            minimum = min(minimum, a[mid]);
            high = mid - 1;  // discard right half
        }
    }
    return minimum;
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    // cout << bruteForce(a,n);
    // cout << optimal1(a,n);
    // cout << optimal2(a,n);
    cout << optimalDuplicated(a,n);
    
    return 0;
}



