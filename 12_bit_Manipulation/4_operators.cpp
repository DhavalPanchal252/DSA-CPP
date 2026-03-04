#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 5;   // 0101
    int b = 3;   // 0011

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "\n===== AND (&) =====" << endl;
    cout << "a & b = " << (a & b) << endl;   // 0101 & 0011 = 0001

    cout << "\n===== OR (|) =====" << endl;
    cout << "a | b = " << (a | b) << endl;   // 0101 | 0011 = 0111

    cout << "\n===== XOR (^) =====" << endl;
    cout << "a ^ b = " << (a ^ b) << endl;   // 0101 ^ 0011 = 0110

    cout << "\n===== NOT (~) =====" << endl;
    cout << "~a = " << (~a) << endl;         // flips all bits

    cout << "\n===== LEFT SHIFT (<<) =====" << endl;
    cout << "a << 1 = " << (a << 1) << endl; // multiply by 2
    cout << "a << 2 = " << (a << 2) << endl; // multiply by 4

    cout << "\n===== RIGHT SHIFT (>>) =====" << endl;
    cout << "a >> 1 = " << (a >> 1) << endl; // divide by 2
    cout << "a >> 2 = " << (a >> 2) << endl; // divide by 4

    return 0;
}