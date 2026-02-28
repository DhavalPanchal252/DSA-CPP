// same as next greatest element
#include <bits/stdc++.h>
using namespace std;

// TC : O(n*n) , SC : O(1)
int bruteForce(vector<int> &a1,int n){

    int total = 0;

    for(int i=1 ; i<n-1 ; i++){//n

        int leftMax = *max_element(a1.begin() , a1.begin()+i);//n
        int rightMax = *max_element(a1.begin() +i+1 , a1.end());//n

        int water = min(leftMax,rightMax) - a1[i];

        if(water > 0) total += water;
    }
    return total;
}
// TC : O(n) , SC : O(n)
int better(vector<int> &a1,int n){

    int total = 0;

    vector<int> prefixSum;//n
    vector<int> suffixSum;//n

    int maxi = a1[0];
    prefixSum.push_back(maxi);
    for(int i=1 ; i<n ; i++){//n
        maxi = max(maxi,a1[i]);
        prefixSum.push_back(maxi);
    }

    maxi = a1[n-1];
    suffixSum.push_back(maxi);
    for(int i=n-2 ; i>=0 ; i--){//n
        maxi = max(maxi,a1[i]);
        suffixSum.push_back(maxi);
    }

    reverse(suffixSum.begin(),suffixSum.end());

    for(int i=1 ; i<n-1 ; i++){ // n

        int leftMax = prefixSum[i];
        int rightMax = suffixSum[i];

        int water = min(leftMax,rightMax) - a1[i];

        if(water > 0) total += water;
    }
    return total;
}

// TC : O(n) , SC : O(1)
int optimal(vector<int> &a1,int n){

    int l = 0;
    int r = n-1;

    int leftMax = 0;
    int rightMax = 0;
    int total = 0;

    while(l < r){
        if(a1[l] <= a1[r]){
            if(a1[l] < leftMax){
                total += leftMax - a1[l];
            }
            else{
                leftMax = a1[l];
            }
            l++;
        }
        else{
            if(a1[r] < rightMax){
                total += rightMax - a1[r];
            }
            else{
                rightMax = a1[r];
            }
            r--;
        }
    }
    return total;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(auto &i : arr1) cin >> i;

    // cout << bruteForce(arr1,n);
    // cout << better(arr1,n);
    cout << optimal(arr1,n);
    return 0;
}