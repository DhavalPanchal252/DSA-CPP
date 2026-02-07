#include <bits/stdc++.h>
using namespace std;

int Quick(int a[],int low,int high){

    int i=low;
    int j=high;
    int pivot = a[low];
    while(i<j){

        while(pivot>=a[i] && (i<=high-1)){ // i<=high  :  will cause index outof bound b due to i++
            i++;
        }

        while(pivot<a[j] && (j>=low+1)){
            j--;
        }

        if(i<j) swap(a[i],a[j]);

    }
    swap(a[low],a[j]);
    return j;
}

void QuickSort(int a[],int low,int high){

    if(low<high){

        int p = Quick(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    QuickSort(arr,0,n-1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
