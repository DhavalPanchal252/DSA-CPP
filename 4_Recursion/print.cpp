#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void print(){

    
    if(cnt==3) return;
    
    cnt++;
    cout << cnt << endl;
    print();
}
int main(){
    

    print();   
    return 0;
}