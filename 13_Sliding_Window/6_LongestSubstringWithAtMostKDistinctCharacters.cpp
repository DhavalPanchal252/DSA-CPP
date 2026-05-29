#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and an integer k,
return the length of the longest substring
that contains at most k distinct characters.
*/


// TC : O(N^2) , SC : O(K)
int bruteForce(string str, int k){

    int n = str.size();

    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){

        unordered_set<char> st;

        for(int j = i ; j < n ; j++){

            st.insert(str[j]);

            if(st.size() <= k){
                maxLen = max(maxLen , j - i + 1);
            }
            else{
                break;
            }
        }
    }

    return maxLen;
}


// TC : O(N) , SC : O(K)
int optimal(string str , int k){

    int n = str.size();

    int l = 0;
    int r = 0;

    int maxLen = 0;

    unordered_map<char,int> freq;

    while(r < n){

        freq[str[r]]++;

        while(freq.size() > k){

            freq[str[l]]--;

            if(freq[str[l]] == 0){
                freq.erase(str[l]);
            }

            l++;
        }

        if(freq.size() <= k){
            maxLen = max(maxLen , r - l + 1);
        }

        r++;
    }

    return maxLen;
}


int main(){

    string str;
    cin >> str;

    int k;
    cin >> k;

    // cout << bruteForce(str, k);
    cout << optimal(str, k);

    return 0;
}