#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,4,10,20,7};
    
    int max = *max_element(a,a+6);
    cout << max ;
    return 0;
}