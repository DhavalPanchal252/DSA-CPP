#include <bits/stdc++.h>
using namespace std;

/*
Leetcode 76 : Minimum Window Substring

Given two strings s and t,
return the minimum window substring of s
such that every character in t
(including duplicates) is included in the window.

If there is no such substring, return "".
*/


// TC : O(N^2) , SC : O(256)

string bruteForce(string s , string t){

    int n = s.size();
    int m = t.size();

    int start = -1;

    int minLen = INT_MAX;

    for(int i = 0 ; i < n ; i++){

        vector<int> hashh(256,0);

        for(auto &ch : t){
            hashh[ch]++;
        }

        int cnt = 0;

        for(int j = i ; j < n ; j++){

            if(hashh[s[j]] > 0){
                cnt++;
            }

            hashh[s[j]]--;

            if(cnt == m){

                if(j - i + 1 < minLen){

                    minLen = j - i + 1;

                    start = i;
                }

                break;
            }
        }
    }

    if(start == -1) return "";

    return s.substr(start, minLen);
}



// TC : O(N + M) , SC : O(256)

string optimal(string s , string t){

    int n = s.size();
    int m = t.size();

    vector<int> hashh(256,0);

    for(auto &ch : t){
        hashh[ch]++;
    }

    int l = 0;
    int r = 0;

    int cnt = 0;

    int minLen = INT_MAX;
    int start = -1;

    while(r < n){

        if(hashh[s[r]] > 0) cnt++;

        hashh[s[r]]--;

        while(cnt == m){

            if(r - l + 1 < minLen){

                minLen = r - l + 1;

                start = l;
            }

            hashh[s[l]]++;

            if(hashh[s[l]] > 0) cnt--;
                
            l++;
        }

        r++;
    }

    if(start == -1) return "";

    return s.substr(start, minLen);
}


int main(){

    string s, t;

    cin >> s;
    cin >> t;

    // cout << bruteForce(s, t);
    cout << optimal(s, t);

    return 0;
}