#include <bits/stdc++.h>
using namespace std;

void selection(int arr[],int i, int n) {

        if(i >= n-1) return; // base case
    
        int minIndex = i; // assume current index is min

        for (int j = i + 1; j <= n-1; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap arr[i] with arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    
        selection(arr,i+1,n);

}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    selection(arr,0, n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
