#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n , vector<int> &arr , int target){

    int i = 0 ;
    int j = arr.size()-1;

    while(i <= j){
        int mid = j+(i-j)/2;

        if(target == arr[mid]) 
            return mid;
        else if(target < arr[mid]) 
            j = mid-1;
        else 
            i = mid+1;
    }
    
    return i;
    
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0 ; i<n ; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout <<  binarySearch(n,arr,target);
    return 0;
}