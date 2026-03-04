#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        DIVIDE TWO INTEGERS
Divide two integers without using *, /, %
==================================================
*/


// --------------------------------------------------
// 1️⃣ Brute Force
// TC: O(|dividend/divisor|)
// SC: O(1)
// --------------------------------------------------
int bruteForce(int dividend, int divisor) {

    if(dividend == divisor) return 1;

    int sign = 1;

    if(dividend > 0 && divisor < 0) sign = -1;
    if(dividend < 0 && divisor > 0) sign = -1;

    long long n = llabs((long long)dividend);
    long long m = llabs((long long)divisor);

    long long ans = 0;

    // Repeated subtraction
    while(n >= m){
        n -= m;
        ans++;
    }

    ans = (sign == 1) ? ans : -ans;

    if(ans > INT_MAX) return INT_MAX;
    if(ans < INT_MIN) return INT_MIN;

    return (int)ans;
}


// --------------------------------------------------
// 2️⃣ Optimal (Bit Manipulation)
// TC: O(log² N)
// SC: O(1)
// --------------------------------------------------
int optimal(int dividend, int divisor) {

    /*
    IDEA:

    Instead of subtracting divisor one-by-one,
    we subtract the largest possible power-of-two
    multiple of the divisor.

    divisor * 2^k  →  divisor << k

    Example:
        40 / 3

        3 * 8 = 24
        3 * 4 = 12
        3 * 1 = 3

        quotient = 8 + 4 + 1 = 13
    */

    if(dividend == divisor) return 1;

    int sign = 1;

    if(dividend > 0 && divisor < 0) sign = -1;
    if(dividend < 0 && divisor > 0) sign = -1;

    long long n = llabs((long long)dividend);
    long long m = llabs((long long)divisor);

    long long ans = 0;

    while(n >= m){

        int cnt = 0;

        // Find largest shift
        while(n >= (m << (cnt + 1))){ // m * 2^(cnt+1)
            cnt++;
        }

        ans += 1LL << cnt; // 2^(cnt)

        n = n - m * (1LL << cnt);
    }

    ans = (sign == 1) ? ans : -ans;

    if(ans > INT_MAX) return INT_MAX;
    if(ans < INT_MIN) return INT_MIN;

    return (int)ans;
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    int dividend = 40;
    int divisor = 3;

    cout << "Brute Force Result: "
         << bruteForce(dividend, divisor) << endl;

    cout << "Optimal Result: "
         << optimal(dividend, divisor) << endl;

    return 0;
}