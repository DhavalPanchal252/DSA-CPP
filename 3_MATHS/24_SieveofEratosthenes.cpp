#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        COUNT PRIMES (Sieve of Eratosthenes)
Count the number of prime numbers strictly less than n
==================================================
*/


// --------------------------------------------------
// Optimal Approach
// TC: O(n log log n)
// SC: O(n)
// --------------------------------------------------
int countPrimes(int n) {

    // Edge case
    if(n <= 2) return 0;

    // Assume all numbers are prime initially
    vector<bool> isPrime(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    // Mark multiples of primes
    for(int i = 2; i * i < n; i++){

        if(isPrime[i]){

            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
    }

    int cnt = 0;

    // Count remaining primes
    for(int i = 2; i < n; i++){
        if(isPrime[i])
            cnt++;
    }

    return cnt;
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main(){

    int n = 10;

    int result = countPrimes(n);

    cout << "Number of primes less than " << n << " = " << result << endl;

    return 0;
}