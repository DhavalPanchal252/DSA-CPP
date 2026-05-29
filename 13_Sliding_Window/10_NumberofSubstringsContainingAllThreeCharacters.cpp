#include <bits/stdc++.h>
using namespace std;

/*
Leetcode 1358 : Number of Substrings Containing All Three Characters

Given a string s consisting only of characters:
'a', 'b', and 'c'.

Return the number of substrings containing
at least one occurrence of all three characters.
*/


// TC : O(N^2) , SC : O(1)

int bruteForce(string str){

    int n = str.size();

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){

        vector<int> freq(3,0);

        for(int j = i ; j < n ; j++){

            freq[str[j] - 'a']++;

            if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                cnt++;
            }
        }
    }

    return cnt;
}



// TC : O(N) , SC : O(1)

int optimal(string str){

    int n = str.size();

    int l = 0;
    int r = 0;

    int cnt = 0;

    vector<int> freq(3,0);

    while(r < n){

        freq[str[r] - 'a']++;

        while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){

            cnt += (n - r);

            freq[str[l] - 'a']--;

            l++;
        }

        r++;
    }

    return cnt;
}


int main(){

    string str;
    cin >> str;

    // cout << bruteForce(str);
    cout << optimal(str);

    return 0;
}