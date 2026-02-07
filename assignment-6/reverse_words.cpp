#include <bits/stdc++.h>
using namespace std;
// TC:O(n) and SC: O(n)
int main() {
    string s;
    getline(cin, s);

    // remove leading/trailing spaces outside quotes (if any)
    while (!s.empty() && isspace(s.front())) s.erase(s.begin());
    while (!s.empty() && isspace(s.back())) s.pop_back();

    // remove surrounding quotes only if both exist
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        s = s.substr(1, s.size() - 2);
    }

    // now split by whitespace
    stringstream ss(s);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    // print final output enclosed in quotes
    cout << "\"";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i != words.size() - 1) cout << " ";
    }
    cout << "\"" << endl;

    return 0;
}
