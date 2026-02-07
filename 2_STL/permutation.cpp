#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "123";
    sort(s.begin(),s.end());
    // firstly do sort function bcz if given string is 231 then it permutes only 231 -> 312 -> 321
    do{
        cout << s << endl;
    }while(next_permutation(s.begin(),s.end()));
    return 0;
}