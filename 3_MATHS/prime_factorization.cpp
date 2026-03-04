#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        PRIME FACTORS OF A NUMBER
Return all unique prime factors of n
==================================================
*/


// --------------------------------------------------
// Optimal Approach
// TC: O(sqrt(n))
// SC: O(k)   (k = number of prime factors)
// --------------------------------------------------
vector<int> primeFac(int n) {

    vector<int> ans;

    // Check divisibility from 2 to sqrt(n)
    for(int i = 2; i <= sqrt(n); i++){

        if(n % i == 0){

            // i is a prime factor
            ans.push_back(i);

            // Remove all occurrences of this factor
            while(n % i == 0){
                n = n / i;
            }
        }
    }

    // If remaining n is greater than 1,
    // it is also a prime factor
    if(n != 1)
        ans.push_back(n);

    return ans;
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {

    int n = 84;

    vector<int> ans = primeFac(n);

    cout << "Prime Factors: ";

    for(auto &i : ans)
        cout << i << " ";

    cout << endl;

    return 0;
}