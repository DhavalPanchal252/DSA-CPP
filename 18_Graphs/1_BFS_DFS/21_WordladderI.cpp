#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Word Ladder

                    BFS

--------------------------------------------------

Problem:

Transform beginWord into endWord.

Rules:

1. Change only one character at a time.
2. Every transformed word must exist
   in the given dictionary.

Return the minimum number of words
in the transformation sequence.

--------------------------------------------------

Approach:

Since every transformation has the
same cost (1 step),

=> Use BFS.

Each level of BFS represents one
transformation.

--------------------------------------------------

Steps:

1. Store all dictionary words in a set.
2. Push beginWord into queue.
3. Remove visited words from the set.
4. Try changing every character from
   'a' to 'z'.
5. If generated word exists in the set,
   push it into the queue.
6. First time we reach endWord,
   return the current level.

--------------------------------------------------

Time Complexity :

O(N × L × 26)

N = Number of words
L = Length of each word

Space Complexity :

O(N)

==================================================
*/

int ladderLength(string beginWord,
                 string endWord,
                 vector<string>& wordList) {

    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;

    q.push({beginWord, 1});

    // Mark beginWord as visited
    st.erase(beginWord);

    while (!q.empty()) {

        string word = q.front().first;
        int steps = q.front().second;

        q.pop();

        if (word == endWord)
            return steps;

        // Try changing every character

        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (st.find(word) != st.end()) {

                    st.erase(word);

                    q.push({word, steps + 1});
                }
            }

            // Restore original character
            word[i] = original;
        }
    }

    return 0;
}

int main() {

    /*
            beginWord = hit

            endWord = cog

            Dictionary

            hot
            dot
            dog
            lot
            log
            cog

            Transformation

            hit
             ↓
            hot
             ↓
            dot
             ↓
            dog
             ↓
            cog

            Answer = 5
    */

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {

        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    int ans = ladderLength(beginWord,
                           endWord,
                           wordList);

    cout << "Shortest Transformation Length : "
         << ans << endl;

    return 0;
}