#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(n), as we iterate through the array only once.

Space Complexity: O(n) as we are using another array of size, same as the given array.
*/
void bruteForce(int a[],int n){

    int temp[n];

    for(int i=1;i<=n;i++){

        temp[i-1] = a[i];
    }

    temp[n-1] = a[0];

    for(int i=0;i<n;i++){
        cout << temp[i] << " ";
        }

}
/*
Time Complexity: O(n), as we iterate through the array only once.

Space Complexity: O(1) as no extra space is used
*/
void optimal(int a[],int n){

    int temp = a[0];

    for(int i = 1;i<n;i++){

        a[i-1]=a[i];
    }
    a[n-1]= temp;

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){

        cin >> arr[i];
    }

    bruteForce(arr,n);
    cout<<endl;
    optimal(arr,n);

    return 0;
}