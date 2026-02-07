#include <bits/stdc++.h>
using namespace std;
// TC of bubble sort is O(n^2) but for sorted(increasing)  Tc : O(n) 
void bubble(int arr[],int n){
    for (int i=n-1;i>=0;i--){

        int ISswap = 0;

        for (int j=0;j<=i-1;j++){

                if(arr[j]>arr[j+1]){
                    // int temp = arr[j+1];
                    // arr[j+1]= arr[j];
                    // arr[j] = temp;
                    swap(arr[j+1],arr[j]);

                    ISswap = 1;
                }
        }
        cout <<ISswap << endl; // print 0 if already sorted(increasing)
        if(ISswap == 0) break;

    }

}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubble(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
