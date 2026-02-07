#include <bits/stdc++.h>
using namespace std;

int value(int a){ // call by value

    a++;
    cout << "hello..." << a << endl;
}

int reference(int &i){ // call by reference

    i++;
    cout << "hello..." << i << endl;
}

int main(){
    int i=10;

    value(i);
    cout << "after callby value : " << i << endl;

    reference(i);
    cout << "after callby reference : " << i << endl;

    
    return 0;
}