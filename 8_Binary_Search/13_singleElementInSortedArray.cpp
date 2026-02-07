#include <bits/stdc++.h>
using namespace std;

int bruteForce1(vector<int> &a , int n){ // TC : O(n) , SC : O(1)
    
    if(a[0] != a[1]) return a[0];
    else if (n==1) return a[0];
    else if(a[n-1] != a[n-2]) return a[n-1];
    else{
        for(int i = 1 ; i<n-1 ; i++){
    
            if(a[i-1] != a[i] && a[i] != a[i+1]){
                return a[i];
            }   
        }
    }
}

int bruteForce2(vector<int> &a , int n){ // TC : O(n) , SC : O(1)
    
    int xorr = 0;
    for(int i = 0 ; i<n ; i++){
        xorr ^= a[i];
    }
    return xorr;
}

/*
left half : even,odd
right half : odd,even
*/

// this is MY method 😊
int optimal(vector<int> &a , int n){ // TC : O(log n) , SC : O(1)

    // If only one element, it must be the answer
    if(n == 1) return a[0];

    // If first element is different from second, it is the single element
    else if(a[0] != a[1]) return a[0];

    // If last element is different from second last, it is the single element
    else if(a[n-1] != a[n-2]) return a[n-1];

    // Binary search will be performed in the range [1, n-2]
    int low = 1;
    int high = n - 2;

    while(low <= high){

        // Calculate mid safely
        int mid = low + (high - low) / 2;

        // Check if mid is part of a pair (same as left or right neighbor)
        if(a[mid] == a[mid-1] || a[mid] == a[mid+1]){

            /*
               Using index parity to decide the search direction:
               - Before the single element, pairs start at even indices
               - After the single element, pairs start at odd indices

               Case 1:
               mid is even AND it is not paired with mid+1
               → single element lies on the right side

               Case 2:
               mid is odd AND it is paired with mid-1
               → single element lies on the right side
            */
            if((mid % 2 == 0 && a[mid] != a[mid+1]) ||
               (mid % 2 == 1 && a[mid] == a[mid-1])){

                // Move search space to the right half
                low = mid + 1;
            }
            else{
                // Move search space to the left half
                high = mid - 1;
            }
        }
        else{
            // mid is not equal to neighbors → this is the single element
            return a[mid];
        }
    }

    // This line is never reached for valid input
    return -1;
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    // cout << bruteForce1(a,n);
    // cout << bruteForce2(a,n);
    cout << optimal(a,n);

    return 0;
}



