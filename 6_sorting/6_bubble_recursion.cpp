#include <bits/stdc++.h>
using namespace std;

void bubble(int a[],int n){

    if(n==1) return; // baae case
    
    int ISswap=0;

    for(int i=0;i<=n-2;i++){
        if(a[i]>a[i+1]) swap(a[i],a[i+1]);

        ISswap=1;
    }

    if(ISswap==0) return;
    
    bubble(a,n-1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubble(arr,n);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
