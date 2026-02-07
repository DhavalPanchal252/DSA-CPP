#include <bits/stdc++.h>
using namespace std;
// Brute force: O(n^2)
bool bruteForce(int a[],int n){

    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){

            if(a[j]<a[i]) return false;
        }
    }
    return true;
}

// Optimal approach: O(n)
bool optimalApp(int a[], int n) {

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){

        cin >> arr[i];
    }

    cout << "Brute Force: " << (bruteForce(arr, n) ? "Sorted" : "Not Sorted") << endl;
    cout << "Better App : " << (optimalApp(arr, n) ? "Sorted" : "Not Sorted") << endl;


    return 0;
}