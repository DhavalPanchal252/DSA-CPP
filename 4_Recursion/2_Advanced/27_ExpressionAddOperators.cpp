#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 282 : Expression Add Operators
---------------------------------------------------------

Given a string num containing only digits
and an integer target,

Return all possible expressions by inserting:

+
-
*

between digits so that the expression
evaluates to target.

Operands should not contain leading zeros.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:

123
6

Output:

1+2+3
1*2*3

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Use Backtracking

2. At every index:
      take substring as current number

3. Then try operators:
      +
      -
      *

4. Maintain:
      - current expression
      - current evaluated value
      - previous operand

5. Multiplication requires special handling
   because of operator precedence

---------------------------------------------------------
Multiplication Formula:
---------------------------------------------------------

newValue =
value - prev + (prev * currNum)

Example:

1 + 2 * 3

value = 3
prev = 2

newValue:

3 - 2 + (2*3)
= 7

---------------------------------------------------------
Leading Zero Condition:
---------------------------------------------------------

Avoid:

05
00
012

Only single "0" allowed.

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If index reaches end of string
and value == target:

store expression

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

Approximately:

O(4^n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(n)

(recursion stack)

---------------------------------------------------------
*/

void helper(int ind,
            string num,
            int target,
            string curr,
            long value,
            long long prev,
            vector<string> &ans){

    // reached end

    if(ind == num.size()){

        if(value == target){

            ans.push_back(curr);
        }

        return;
    }

    string currStr = "";

    long currNum = 0;

    // try all substrings

    for(int i = ind; i < num.size(); i++){

        // leading zero check

        if(i != ind && num[ind] == '0'){

            break;
        }

        currStr += num[i];

        currNum =
            currNum * 10 + (num[i] - '0');

        // first number

        if(ind == 0){

            helper(i + 1,
                    num,
                    target,
                    currStr,
                    currNum,
                    currNum,
                    ans);
        }

        else{

            // addition

            helper(i + 1,
                    num,
                    target,
                    curr + "+" + currStr,
                    value + currNum,
                    currNum,
                    ans);

            // subtraction

            helper(i + 1,
                    num,
                    target,
                    curr + "-" + currStr,
                    value - currNum,
                    -currNum,
                    ans);

            // multiplication

            helper(i + 1,
                    num,
                    target,
                    curr + "*" + currStr,
                    value - prev + (prev * currNum),
                    prev * currNum,
                    ans);
        }
    }
}


vector<string> addOperators(string num , int target){

    vector<string> ans;

    helper(0,
            num,
            target,
            "",
            0,
            0,
            ans);

    return ans;
}



int main(){

    string num;

    cin >> num;

    int target;

    cin >> target;

    vector<string> ans = addOperators(num, target);

    for(auto &expr : ans){

        cout << expr << endl;
    }

    return 0;
}