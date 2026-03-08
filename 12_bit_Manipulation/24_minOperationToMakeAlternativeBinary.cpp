#include <bits/stdc++.h>
using namespace std;

/*
==================================================
 MIN OPERATIONS TO MAKE BINARY STRING ALTERNATING
==================================================
*/


// --------------------------------------------------
// 1️⃣ Brute Force (Your Approach - Bit Conversion)
// TC: O(n)
// SC: O(1)
// NOTE: Works only when n ≤ 60 (fits in long long)
// --------------------------------------------------
int bruteForce(string s){

    int n = s.size();
    long long ans = 0;

    // Convert binary string → number
    for(char c : s){
        ans = ans * 2 + (c - '0');
    }

    // Build pattern 010101...
    long long num = 0;

    for(int i = 0; i < n; i++){
        num <<= 1;
        if(i % 2 == 1) num |= 1;
    }

    long long mask = (1LL << n) - 1;

    // Build pattern 101010...
    long long num2 = (~num) & mask;

    return min(__builtin_popcountll(num ^ ans),
               __builtin_popcountll(num2 ^ ans));
}



// --------------------------------------------------
// 2️⃣ Optimal 1 (Pattern Comparison)
// TC: O(n)
// SC: O(1)
// --------------------------------------------------
int optimal1(string s){

    int n = s.size();

    int op1 = 0;
    int op2 = 0;

    for(int i = 0; i < n; i++){

        char p1 = (i % 2 == 0) ? '0' : '1'; // 010101...
        char p2 = (i % 2 == 0) ? '1' : '0'; // 101010...

        if(s[i] != p1) op1++;
        if(s[i] != p2) op2++;
    }

    return min(op1, op2);
}



// --------------------------------------------------
// 3️⃣ Optimal 2 (XOR Trick)
// TC: O(n)
// SC: O(1)
// --------------------------------------------------
int optimal2(string s){

    int diff1 = 0;
    int diff2 = 0;

    for(int i = 0; i < s.size(); i++){

        int bit = s[i] - '0';

        int p1 = (i % 2);        // 010101...
        int p2 = 1 - (i % 2);    // 101010...

        diff1 += (bit ^ p1);
        diff2 += (bit ^ p2);
    }

    return min(diff1, diff2);
}



// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main(){

    string s = "1111";

    cout << "Brute Force Result: "
         << bruteForce(s) << endl;

    cout << "Optimal 1 Result: "
         << optimal1(s) << endl;

    cout << "Optimal 2 Result: "
         << optimal2(s) << endl;

    return 0;
}