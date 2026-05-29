#include <bits/stdc++.h>
using namespace std;

/*
You are visiting a farm that has a single row of fruit trees.

You want to collect as much fruit as possible. However, the owner has some strict rules:

-> You only have two baskets.
-> Each basket can hold only one type of fruit.
-> You can start from any tree.
-> You must pick exactly one fruit from every tree while moving to the right.
-> If you encounter a fruit that cannot fit in your baskets, you must stop.

Return the maximum number of fruits you can collect.
*/


// TC : O(N^2) , SC : O(1)
int bruteForce(vector<int> &arr, int n){

    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){

        unordered_set<int> st;

        for(int j = i ; j < n ; j++){

            st.insert(arr[j]);

            if(st.size() <= 2){
                maxLen = max(maxLen , j - i + 1);
            }
            else{
                break;
            }
        }
    }

    return maxLen;
}


// TC : O(N) , SC : O(1)
int optimal(vector<int> &arr , int n){

    int l = 0;
    int r = 0;
    int maxLen = 0;

    unordered_map<int,int> freq;

    while(r < n){

        freq[arr[r]]++;

        while(freq.size() > 2){

            freq[arr[l]]--;

            if(freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }

            l++;
        }

        if(freq.size() <= 2){
            maxLen = max(maxLen , r - l + 1);
        }

        r++;
    }

    return maxLen;
}


int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    // cout << bruteForce(arr, n);
    cout << optimal(arr, n);

    return 0;
}