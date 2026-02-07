#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int low ,int mid , int high){

    int left = low;
    int right = mid+1;

    vector<int> temp;
    while((left <= mid) && (right <=high)){

        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(a[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(a[right]);
            right++;
    }
/*
low = 2, high = 4
So we’re merging elements a[2], a[3], a[4].

temp = {5, 8, 12}

Now the loop runs:

i = 2 → a[2] = temp[0]

i = 3 → a[3] = temp[1]

i = 4 → a[4] = temp[2]
*/
    for(int i=low;i<=high;i++){
        a[i] = temp[i-low];
    }
}

void mergeSort(int a[],int low , int high){

    // base case :
    if(low>=high) return;

    int mid = (low+high)/2;
    mergeSort(a,low,mid); // recursion
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr,0,n-1);

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
