#include <bits/stdc++.h>
using namespace std;

void bruteForce(int a[],int n){

    set<int> s;

    for(int i =0; i<n;i++){
        s.insert(a[i]); // each insertion in set takes O(logn) , so for n ele takes O(nlogn),,use unsorted_set for O(1) TC
    }
    
    int size_set = s.size();

    for(auto i : s){

        cout << i << " ";
    }
}

void optimal(int a[],int n){

    int i =0;
    for(int j=1;j<n;j++){  // O(n)

        if(a[i]!=a[j]){
            i++;
            a[i]=a[j];
        }
    }


    for(int j=0;j<=i;j++){  // i is the last index of the array
        cout << a[j] << " ";
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