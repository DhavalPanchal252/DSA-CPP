#include <bits/stdc++.h>
using namespace std;
// Method 1 : brute force --> TC : O(min(a,b))
int brutforce(int a,int b){

    int gcd=1;
    for(int i =1 ; i <=  min(a,b) ; i++)
    {
        if(a%i == 0 && b%i == 0){
            gcd = i; // finding greatest so need to write break;
        }
        
    }
    return gcd;
}
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// Method 2 : better approach -->TC : O(min(a,b)) but in practice, it will execute fewer iterations on average.. Better when one number is significantly larger than other
int better(int a,int b){

    int gcd=1;
    for(int i =min(a,b) ; i > 0   ; i--)
    {
        if(a%i == 0 && b%i == 0){
            gcd = i;
            break; // need this break; bcz if we not write then it gives 1 output
        }
        
    }
    return gcd;
}

// Method 3 : Euclidean --> TC : O(min(a,b))
/*
a % b == a - b * floor(a/b)

a = 1000000;
b = 2;
    Using subtraction → 5,00,000 iterations 😩

    Using modulo → Just 1 operation ✅
*/
int euclidiean(int a,int b){
    while(a>0 && b>0){
        if(a>b) a%=b;
        else  b%=a;
    }
    if(a==0) return b;
    else return a;
    
}




int main(){
    int a,b;
    cin >> a;
    cin >> b;

    // cout << "gcd using brute force : " << brutforce(a,b) << endl;
    // cout << "gcd using better approach : " << better(a,b) << endl;
    // cout << "gcd using Eucliean : " << euclidiean(a,b) << endl;
    cout << "gcd using Recursion : " << GCD(a,b) << endl;
    return 0;
}