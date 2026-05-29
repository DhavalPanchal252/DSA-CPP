#include <bits/stdc++.h>
using namespace std;

/*
Minimum Window Subsequence

Given strings s and t,
find the minimum contiguous substring in s
such that t is a subsequence of that substring.

If there is no such window, return "".
*/


// TC : O(N * M)
// SC : O(1)

string optimal(string s , string t){

    int n = s.size();
    int m = t.size();

    int start = -1;
    int minLen = INT_MAX;

    int i = 0 , j = 0;

    while(i < n){

        if(s[i] == t[j]) j++;

        if(j == m){

            int end = i + 1;
            j--;

            while(j >= 0){

                if(s[i] == t[j]) j--;
                i--;
            }

            i++;

            if(end - i < minLen){
                minLen = end - i;

                start = i;
            }

            j = 0;
        }

        i++;
    }

    return start == -1 ? "" : s.substr(start,minLen);
}

int main(){

    string s, t;

    cin >> s;
    cin >> t;

    cout << optimal(s, t);

    return 0;
}