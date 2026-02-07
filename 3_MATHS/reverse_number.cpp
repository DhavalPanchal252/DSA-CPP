#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; //1234
    int rev=0;//4
    while(n!=0){
        int temp;
        temp = n % 10; // 4,3
        n = n/10; // 123,12
        // Check for overflow before it happens
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && temp > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && temp < -8)) return 0;
        
        
        rev = rev*10+temp;//4,43
    }
    cout << rev;
    return 0;
}