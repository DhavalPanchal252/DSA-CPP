#include <bits/stdc++.h>
using namespace std;

/*
Valid Parenthesis String

Given a string s containing:
'(' , ')' and '*'

'*' can represent:
1. '('
2. ')'
3. Empty string

Return true if the string can be made valid.
*/


// --------------------------------------------------
// Pure Recursion Solution
// TC : O(3^N)
// SC : O(N)  [Recursion Stack]
// --------------------------------------------------

bool helper(string &s, int i, int open) {

    if(open < 0)
        return false;

    if(i == s.size())
        return open == 0;

    if(s[i] == '(') {

        return helper(s, i + 1, open + 1);
    }
    else if(s[i] == ')') {

        return helper(s, i + 1, open - 1);
    }
    else { // '*'

        return helper(s, i + 1, open) ||      // empty
               helper(s, i + 1, open - 1) ||  // ')'
               helper(s, i + 1, open + 1);    // '('
    }
}

bool recursion(string s) {

    return helper(s, 0, 0);
}


// --------------------------------------------------
// Greedy Solution (Optimal)
// TC : O(N)
// SC : O(1)
// --------------------------------------------------

bool greedy(string s) {

    // minn = minimum possible unmatched '('
    // maxx = maximum possible unmatched '('

    int minn = 0;
    int maxx = 0;

    for(char ch : s) {

        if(ch == '(') {

            // '(' definitely increases open brackets

            minn++;
            maxx++;
        }
        else if(ch == ')') {

            // ')' definitely decreases open brackets

            minn--;
            maxx--;
        }
        else { // '*'

            /*
                '*' can be:

                1. '('  -> open count +1
                2. ')'  -> open count -1
                3. ""   -> open count unchanged

                So:

                minn--  -> assume '*' acts as ')'
                maxx++  -> assume '*' acts as '('
            */

            minn--;
            maxx++;
        }

        /*
            If maxx becomes negative,
            even the best possible interpretation
            cannot balance the brackets.

            Example:
            s = ")"

            minn = -1
            maxx = -1

            => Invalid
        */
        if(maxx < 0)
            return false;

        /*
            minn cannot be negative.

            If it becomes negative,
            treat some previous '*' as empty
            instead of ')'.
        */
        minn = max(minn, 0);
    }

    /*
        At the end:

        minn == 0
        => There exists at least one way
           to interpret '*' such that all
           brackets are matched.

        minn > 0
        => Some '(' are still unmatched.
    */
    return minn == 0;
}


int main() {

    string s;
    cin >> s;

    cout << "Recursion : "
         << (recursion(s) ? "true" : "false")
         << '\n';

    cout << "Greedy    : "
         << (greedy(s) ? "true" : "false")
         << '\n';

    return 0;
}