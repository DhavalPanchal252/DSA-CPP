#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n)

Space Complexity: O(k) since k array element needs to be stored in temp array
*/
void bruteForce(int a[],int n , int d){
    // if (n == 0) return;
    d = d % n;
    // if (d > n) return;

    int temp[d];

    for(int i = n-d;i<n;i++){
        temp[i-n+d] = a[i];
    }

    for(int i = n-d-1;i>=0;i--){
        a[i+d] = a[i];
    }

    for(int i=0;i<d;i++){
        a[i] = temp[i];
    }

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
/*
Time Complexity - O(N) where N is the number of elements in an array

Space Complexity - O(1) since no extra space is required
*/
void optimal(int a[],int n,int d){
    // if (n == 0) return;
    d = d % n;
    // if (d > n) return;

    reverse(a,a+n-d);
    reverse(a+n-d,a+n);
    reverse(a,a+n);

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

    int d;
    cin >> d;

    // bruteForce(arr,n,d);

    cout<<endl;

    optimal(arr,n,d);

    return 0;
}