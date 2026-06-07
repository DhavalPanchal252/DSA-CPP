#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
Leetcode 1922 : Count Good Numbers
---------------------------------------------------------

A digit string is good if:

1. Digits at even indices are even
   -> 0, 2, 4, 6, 8  (5 choices)

2. Digits at odd indices are prime
   -> 2, 3, 5, 7     (4 choices)

Given an integer n,
return total number of good digit strings of length n.

Since answer can be very large,
return it modulo 1e9 + 7.

---------------------------------------------------------
Approach:
---------------------------------------------------------

Even positions count:
    (n + 1) / 2

Odd positions count:
    n / 2

Total good strings:

    5^(even positions) * 4^(odd positions)

Use Binary Exponentiation
to calculate powers efficiently.

Because:
    n can be as large as 10^15

So O(n) solution gives TLE.

Binary Exponentiation reduces complexity to:

    O(log n)

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(log n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(log n)    // recursion stack

---------------------------------------------------------
*/

long long MOD = 1e9 + 7;

long long power(long long x, long long n){

    if(n == 0) return 1;

    long long half = power(x , n / 2);

    half = (half * half) % MOD;

    if(n % 2 == 1){
        half = (half * x) % MOD;
    }

    return half;
}

int recursion(long long n){

    long long even = (n + 1) / 2;
    long long odd = n / 2;

    return (power(5, even) * power(4, odd)) % MOD;
}

int main(){

    long long n;

    cin >> n;

    cout << recursion(n);

    return 0;
}