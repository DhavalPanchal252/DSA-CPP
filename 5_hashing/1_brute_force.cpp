#include <bits/stdc++.h>
using namespace std;
// TC : O(N) for one key means if we want to search all frequency of keys:Q then O(Q*N)
/*
Now, if the length of the query becomes large like 105 and the array size also becomes large like 105, the time complexity will be O(1010).
*/
int hashh(int key , int a[],int n){
    int cnt =0;
    for (int i=0;i<n;i++)
    {
        if(key == a[i]) cnt+=1;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    cout << hashh(2,a,n);
    return 0;
}