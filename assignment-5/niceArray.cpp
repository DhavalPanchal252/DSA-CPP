#include <bits/stdc++.h>
using namespace std;
// TC:O(n) and SC: O(1)
int niceSubarray( vector<int> &num , int goal){
    
    if(goal < 0) return 0;
    
    int r=0,l=0,sum=0,cnt=0;
    
    while(r < int(num.size())){
        
        sum += (num[r] % 2);
        
        while(sum > goal){
            sum = sum - (num[l] % 2);
            l += 1; 
        }
        
        cnt += (r-l+1);
        r += 1;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> num(n);
    
    for(int i =0 ; i<n ; i++){
        cin >> num[i];
    }
    
    int goal; 
    cin >> goal;
    cout << niceSubarray(num , goal) - niceSubarray(num , goal-1) ;
    return 0;
}
