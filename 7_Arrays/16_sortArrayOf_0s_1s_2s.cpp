#include <bits/stdc++.h>
using namespace std;
// Brute force : Any merge or Quick sort algo

void better(vector<int> &a , int n){ // O(2n)

    int zero=0 , one = 0 , two = 0;

    for(int i = 0 ; i<n ; i++){

        if(a[i] == 0) zero++;
        else if(a[i] ==1) one++;
        else two++;
    }

    for(int i=0 ; i<zero ; i++){
        a[i] = 0;
    }
    for(int i=zero ; i<zero+one ; i++){
        a[i] = 1;
    }
    for(int i=zero+one ; i<zero+one+two ; i++){
        a[i] = 2;
    }
    
    for(int i = 0 ; i<n ; i++){

        cout << a[i] << " ";
    }
}

// Dutch National Flag algorithm.
void optimal(vector<int> &a , int n){ // O(n)

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){

        if(a[mid] == 0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
    for(int i = 0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}
int main(){
    
    int n; 
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i; 
    }

    // better(arr,n);
    optimal(arr,n);

    return 0;
}