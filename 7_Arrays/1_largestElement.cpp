#include <bits/stdc++.h>
using namespace std;
// brute force approach :: first we sort the array then return last element TC : O(nlogn)

// optimal approach:: O(n)
int largest(int a[],int n){
    
    int large = INT_MIN;
    for(int i=0;i<n;i++){

        if(large<a[i]) large=a[i];
    }

    return large;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){

        cin >> arr[i];
    }

    int l = largest(arr,n);

    cout << "Largest element in Array is : " << l;
    return 0;
}