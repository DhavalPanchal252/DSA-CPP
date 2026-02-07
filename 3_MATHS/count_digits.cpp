#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0;
    cin >> n; //1234
    
    while(n!=0){
        int temp;
        temp = n % 10; // 4
        count++;
        n = n/10; // 123
    }
    cout << count << endl;

    
    return 0;
}