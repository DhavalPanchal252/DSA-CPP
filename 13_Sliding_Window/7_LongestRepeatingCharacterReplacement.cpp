#include <bits/stdc++.h>
using namespace std;

/*
Longest Repeating Character Replacement

You are given a string s and an integer k.

You can replace at most k characters in the string
to make all characters in a substring the same.

Return the length of the longest possible substring.
*/


// TC : O(N^2) , SC : O(26)
int bruteForce(string str, int k){

    int n = str.size();

    int maxLen = 0;

    for(int i = 0 ; i < n ; i++){

        int maxFreq = 0;

        vector<int> hashh(26,0);

        for(int j = i ; j < n ; j++){

            hashh[str[j] - 'A']++;

            maxFreq = max(maxFreq, hashh[str[j] - 'A']);

            int changes = (j - i + 1) - maxFreq;

            if(changes <= k){
                maxLen = max(maxLen , j - i + 1);
            }
            else{
                break;
            }
        }
    }

    return maxLen;
}


// TC : O(N) , SC : O(26)
int optimal(string str, int k){

    int n = str.size();

    int l = 0;
    int r = 0;

    int maxLen = 0;
    int maxFreq = 0;

    vector<int> hashh(26,0);

    while(r < n){

        hashh[str[r] - 'A']++;

        maxFreq = max(maxFreq , hashh[str[r] - 'A']);

        while((r - l + 1) - maxFreq > k){

            hashh[str[l] - 'A']--;

            l++;
        }

        maxLen = max(maxLen , r - l + 1);

        r++;
    }

    return maxLen;
}


int main(){

    string str;
    cin >> str;

    int k;
    cin >> k;
Binary Subarrays With Sum
    // cout << bruteForce(str, k);
    cout << optimal(str, k);

    return 0;
}