#include <bits/stdc++.h>
using namespace std;
// TC : O(N) for one key means if we want to search all frequency of keys:Q then O(Q*N)
/*
Now, if the length of the query becomes large like 105 and the array size also becomes large like 105, the time complexity will be O(1010).
*/
int hashh(char key , string a){
    int cnt =0;
    for (int i=0;i<a.size();i++)
    {
        if(key == a[i]) cnt+=1;
    }
    return cnt;
}

int main(){
    string s;
    getline(cin,s);

    char c;
    cin >> c;

    cout << hashh(c,s);
    return 0;
}