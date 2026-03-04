#include <bits/stdc++.h>
using namespace std;

/*
=========================================
        Implement pow(x, n)
Using Binary Exponentiation
=========================================

Time Complexity  : O(log n)
Space Complexity : O(1)
*/

double myPow(double x, int n) {

    // Convert n to long long
    // Important because if n = INT_MIN,
    // -n cannot be stored in int
    long long power = n;

    // If power is negative,
    // convert problem into positive exponent
    if(power < 0) {
        x = 1 / x;       // x^-n = (1/x)^n
        power = -power;
    }

    double result = 1;

    // Binary Exponentiation
    while(power > 0) {

        // If current power is odd,
        // multiply result by x
        if(power & 1) {
            result *= x;
        }

        // Square the base
        x *= x;

        // Divide power by 2
        power >>= 1;
    }

    return result;
}

int main() {

    double x;
    int n;

    cout << "Enter x and n: ";
    cin >> x >> n;

    cout << "Answer: " << myPow(x, n) << endl;

    return 0;
}