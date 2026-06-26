#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Word Ladder II

        BFS using Queue of Paths

--------------------------------------------------

Problem:

Find all shortest transformation
sequences from beginWord to endWord.

Rules:

1. Change only one character.
2. Intermediate word must exist
   in the dictionary.
3. Return all shortest paths.

--------------------------------------------------

Approach:

Instead of storing only words,
store the complete path in the queue.

Queue stores:

[hit]

↓

[hit, hot]

↓

[hit, hot, dot]

↓

...

Whenever endWord is reached,
store the path.

--------------------------------------------------

Level-wise BFS

Words visited in the current level
are removed only after the entire
level is processed.

This allows multiple shortest paths
to use the same word.

--------------------------------------------------

Time Complexity

Worst Case:
Exponential

Space Complexity

Very High
(Stores complete paths)

This solution may give MLE on
very large test cases.

==================================================
*/

vector<vector<string>> findLadders(string beginWord,
                                   string endWord,
                                   vector<string>& wordList) {

    unordered_set<string> st(wordList.begin(),
                             wordList.end());

    queue<vector<string>> q;

    q.push({beginWord});

    vector<string> usedLevel;
    usedLevel.push_back(beginWord);

    int level = 0;

    vector<vector<string>> ans;

    while (!q.empty()) {

        vector<string> topVec = q.front();
        q.pop();

        // New BFS Level

        if (level < topVec.size()) {

            level++;

            for (auto &word : usedLevel)
                st.erase(word);

            usedLevel.clear();
        }

        string word = topVec.back();

        // Reached Destination

        if (word == endWord) {

            if (ans.empty())
                ans.push_back(topVec);

            else if (ans[0].size() == topVec.size())
                ans.push_back(topVec);

            continue;
        }

        // Try changing every character

        for (int i = 0; i < word.size(); i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (st.find(word) != st.end()) {

                    topVec.push_back(word);

                    q.push(topVec);

                    usedLevel.push_back(word);

                    topVec.pop_back();
                }
            }

            word[i] = original;
        }
    }

    return ans;
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

        Shortest Paths

        hit
        hot
        dot
        dog
        cog

        -----------------

        hit
        hot
        lot
        log
        cog
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

    vector<vector<string>> ans =
        findLadders(beginWord,
                    endWord,
                    wordList);

    if (ans.empty()) {

        cout << "No Transformation Exists\n";
    }

    else {

        cout << "All Shortest Paths\n\n";

        for (auto &path : ans) {

            for (auto &word : path) {

                cout << word << " ";
            }

            cout << endl;
        }
    }

    return 0;
}