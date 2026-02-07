#include <bits/stdc++.h>
using namespace std;
// Peak element : a[i-1] < a[i] > a[i+1]

int bruteForce(vector<int> &a, int n){ // TC : O(n) , SC : O(1)

    for(int i=0 ; i<n ; i++){
        if((i==0 || a[i]>a[i+1]) && (i==n-1 || a[i-1] < a[i])){
            return i;
        }
    }
    return -1;
}

int optimal(vector<int> &a, int n){ // TC : O(logn) , SC : O(1)

    if(n == 1) return 0;
    if(a[0]>a[1]) return 0;
    if(a[n-1]>a[n-2]) return n-1;

    int low = 1;
    int high = n-2;

    while(low<=high){
        int mid = low + (high - low)/2;
        // peak condition
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
        // slope is increasing → peak on right
        else if(a[mid]<a[mid+1])
            low = mid+1;
        // slope is decreasing → peak on left
        else 
            high = mid-1;
        
    }
    return -1;

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
