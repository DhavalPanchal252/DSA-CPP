/*
you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.
*/

#include <bits/stdc++.h>
using namespace std;

// TC : O(2K) , SC : O(1)
int optimal(vector<int> &arr , int n , int k){

    int l = 0 , r = n - 1;

    int lsum = 0 , rsum = 0;

    int maxSum = 0 ;

    while(l < k){ // O(k)
        lsum += arr[l];
        l++;
    }

    maxSum = lsum;

    while(l > 0){ // O(k)

        l--;

        lsum -= arr[l];
        rsum += arr[r];

        r--;

        maxSum = max(maxSum , lsum + rsum);
    }

    return maxSum;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int k;
    cin >> k;

    cout << optimal(arr, n, k);

    return 0;
}