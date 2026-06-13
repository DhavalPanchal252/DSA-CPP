#include <bits/stdc++.h>
using namespace std;

/*
Lemonade Change

Each lemonade costs $5.

Customers pay with bills of $5, $10, or $20
in the given order.

Initially, you have no money for change.

Return true if you can provide the correct
change to every customer, otherwise return false.
*/


// TC : O(N)
// SC : O(1)
bool lemonadeChange(vector<int>& bills) {

    int five = 0;
    int ten = 0;

    for(auto &bill : bills) {

        if(bill == 5) {
            five++;
        }
        else if(bill == 10) {

            if(five > 0) {
                five--;
                ten++;
            }
            else {
                return false;
            }
        }
        else { // bill == 20

            if(five > 0 && ten > 0) {
                five--;
                ten--;
            }
            else if(five >= 3) {
                five -= 3;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<int> bills(n);

    for(auto &bill : bills) {
        cin >> bill;
    }

    cout << (lemonadeChange(bills) ? "true" : "false");

    return 0;
}