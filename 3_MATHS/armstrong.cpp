#include <bits/stdc++.h>
using namespace std;
bool isArmst(int num)
{
    int len = to_string(num).length();
    int sum=0;
    int n = num;

    while(n>0){

        int temp = n%10;
        sum += round(pow(temp,len)); // bcz pow() returns float value
        n/=10;
    }

    return sum == num ;
}
int main(){
    int a;
    cin >> a;
    if(isArmst(a)) cout << a << " : is a Armstrong number ";
    else cout << a << " : is not a Armstrong number ";
    return 0;
}

