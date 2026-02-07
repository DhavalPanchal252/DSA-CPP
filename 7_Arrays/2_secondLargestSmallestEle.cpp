#include <bits/stdc++.h>
using namespace std;

/*
BruteForce approach :  O(nlogn) for sorting the array
Sort the array in ascending order
The element present at the second index is the second smallest element
The element present at the second index from the end is the second largest element
*/
void bruteForce(int a[],int n){

    if(n==0 || n==1){
        cout << -1 << " " << -1;
    }

    sort(a,a+n); // sort the array 

    int small = a[1];
    int large = a[n-2];
    
    cout << "second smallest element : " << small << endl;
    cout << "second largest element : " << large << endl;
}
/*
Better approach : O(2n)
Find the smallest and largest element in the array in a single traversal
After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
Similarly, we would find the largest element which is just smaller than the largest element we just found
Indeed, this is our second smallest and second largest element.
*/

void betterApp(int a[],int n){
    
    if(n==0 || n==1) cout << -1 << " " << -1; 

    int small = INT_MAX;
    int second_small = INT_MAX;
    int large = INT_MIN;
    int second_large = INT_MIN;

    for(int i=0;i<n;i++){ // finding largest and smallest element

        if(small > a[i]) small = a[i];
        if(large < a[i]) large = a[i];
    }
    for(int i=0;i<n;i++){ // finding largest and smallest element

        if(a[i]<second_small && a[i]!=small){

            second_small = a[i];
        }
        if(a[i]>second_large && a[i]!=large){

            second_large = a[i];
        }
    }
    cout << "second smallest element : " << second_small << endl;
    cout << "second largest element : " << second_large << endl;
}

/*
Optimal approach : O(n)
*/
int second_smallest(int a[],int n){

    if(n<2) return -1;

    int smallest= INT_MAX , second_small = INT_MAX;

    for(int i=0 ; i< n ; i++){

        if(a[i]<smallest){
            second_small = smallest;
            smallest = a[i];
        }
        else if(a[i] < second_small && (a[i] != smallest)){
            second_small = a[i];
        }
    }
    return second_small;
}
int second_largest(int a[],int n){

    if(n<2) return -1;

    int largest = INT_MIN , second_large=INT_MIN;

    for(int i=0 ; i< n ; i++){

        if(a[i]>largest){
            second_large = largest;
            largest = a[i];
        }
        else if(a[i] > second_large && (a[i] != largest)){
            second_large = a[i];
        }
    }
    return second_large;
}

void optimalApp(int a[],int n){

    
    int sMax = second_largest(a,n);
    int sMin = second_smallest(a,n);

    cout << "second smallest element : " << sMin << endl;
    cout << "second largest element : " << sMax << endl;
}


int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){

        cin >> arr[i];
    }

    bruteForce(arr,n);
    betterApp(arr,n);
    optimalApp(arr,n);

    return 0;
}