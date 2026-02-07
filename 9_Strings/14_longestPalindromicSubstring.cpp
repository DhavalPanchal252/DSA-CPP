#include <bits/stdc++.h>
using namespace std;

int helper(string &s, int left, int right) { // n
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}



//  TC : O(n^2) , SC : O(1)
string optimal(string &s) {

    

    int start = 0, end = 0;

    for (int center = 0; center < s.size(); center++) { // n

        int oddLen = helper(s, center, center); // n
        int evenLen = helper(s, center, center + 1);

        int maxLen = max(oddLen, evenLen);

        if (maxLen > end - start + 1) {

            start = center - (maxLen - 1) / 2;
            end = center + maxLen / 2;
        }
    }

    return s.substr(start, end - start + 1);
}


int main() {
    string s;
    cin >> s;

    cout << optimal(s);
    return 0;
}
