#include <bits/stdc++.h>
using namespace std;
//  Tc = O(n^2) but... best Tc = O(n) when already sorted ... inner loop never runs
void insert(int arr[],int i,int n){
        
        if(n==i) return; // base case

        int j=i;

        while(j>0 && arr[j-1]>arr[j]){

            // int temp = arr[j];
            // arr[j]= arr[j-1];
            // arr[j-1]=temp;
            swap(arr[j],arr[j-1]);
            j--;
        }

    insert(arr,i+1,n);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    insert(arr, 0, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
