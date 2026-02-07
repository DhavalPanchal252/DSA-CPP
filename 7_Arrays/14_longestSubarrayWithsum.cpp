#include <bits/stdc++.h>
using namespace std;
 
void bruteForce(vector<int> &arr , int n , int k){ // O(n^3)

    int len = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){

            int sum = 0 ; 
            for(int k = i ; k<=j ; k++){
                sum += arr[k];
            }

            if(sum == k){
                len = max(len , j-i+1);
            }
        }
    }
    cout << len;
}
void bruteForceBetter(vector<int> &arr , int n , int k){ // O(n^2)

    int len = 0;
    for(int i = 0 ; i<n ; i++){
        int sum = 0 ;
        for(int j=i ; j<n ; j++){

            sum += arr[j];

            if(sum == k){
                len = max(len , j-i+1);
            }
        }
    }
    cout << len;
}

// this is optimal solution if array has negative and positive values
// if values of array is negative also then we can reduce TC further better solution 
void better(vector<int> &arr , int n , int k){ // TC : O(n x log n) , SC : O(n)
    map<int,int> mapp; // O(log n)
    // unordered_map<int,int> mapp; // O(n)

    int sum = 0 ;
    int len = 0;
    for(int i = 0 ; i<n ; i++){

        sum += arr[i];
    
        if(sum ==  k){
            len = max(len,i+1);
        }
        
        // if(mapp.find(sum-k) != mapp.end()){
        //     len = max(len ,i - mapp[sum-k]);
        // }
        for(auto key : mapp){
            if(key.first == (sum-k)){
                len = max(len , i-key.second);
            }
        } 
        
        // stores only if sum is not stored in mapp , other wise same sum will over writes the value
        if(mapp.find(sum) == mapp.end()){
            mapp[sum] = i;
        }
    }
    cout << len;
}

// Value has only positive values then optimal solution is exists
void optimal(vector<int> &arr,int n , int k) { // O(2n)

    int left = 0;
    int right = 0;
    int sum = 0;
    int len = 0;

    while(right < n){ // O(n)

        sum += arr[right];

        // shrink window if sum > k
        while(sum > k && left <= right){ // overall this time takes O(n)
            sum -= arr[left];
            left++;
        }

        // check answer
        if(sum == k){
            len = max(len, right - left + 1);
        }

        right++;
    }
    cout << len;
}


int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i; 
    }

    int k;
    cin >> k;
    // bruteForce(arr,n,k);
    // bruteForceBetter(arr,n,k);
    // better(arr , n  , k);
    optimal(arr , n , k);
    return 0;
}