#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n) {// TC : O(n^2) , SC : O(1)
    int repeating = -1 ,missing = -1;

    for(int i=1 ; i<=n ; i++){
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(i == a[j]) cnt++;
        }
        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;

        if(repeating != -1 && missing != -1 ) break;
    }
    cout << repeating << endl;
    cout << missing ;
}

void better(vector<int> &a , int n){ // TC : O(n) , SC : O(n)
    int repeating = -1 , missing = -1;
    unordered_map<int,int > mapp;

    for(int i=0 ; i<n ; i++){
        mapp[a[i]]++ ;
    }

    for(int i=1 ; i<=n ; i++){
        if(mapp[i] == 2 ) repeating = i;
        else if(mapp[i] == 0 ) missing = i;

        if(repeating != -1 && missing != -1) break;
    }

    cout << repeating << endl;
    cout << missing << endl;
}
/*
First, calculate the sum of all elements in the given array, denoted as S, and the sum of natural numbers from 1 to N, denoted as Sn. The formula for Sn is (N * (N + 1)) / 2.
Now calculate S - Sn. This gives us X - Y, where X is the repeating number and Y is the missing number.
Next, calculate the sum of squares of all elements in the array, denoted as S2, and the sum of squares of the first N numbers, denoted as S2n. The formula for S2n is (N * (N + 1) * (2N + 1)) / 6.
Now calculate S2 - S2n. This gives us X2 - Y2.
From the equations S - Sn = X - Y and S2 - S2n = X2 - Y2, we can compute X + Y by the formula (S2 - S2n) / (S - Sn).
Using the values of X + Y and X - Y, we can solve for X and Y through simple addition and subtraction.
Finally, return the values of X (the repeating number) and Y (the missing number).
*/
void optimal(vector<int> &a , int n){// TC : O(n) , SC : O(1)

    long long sum1=0;
    long long sumS1 = 0;
    for(auto &i : a) {
        sum1 += 1LL*i;
        sumS1 += 1LL*i*i ;
    }

    long long sum2 = n*(n+1)/2;
    long long sumS2 = n*(n+1)*(2*n+1)/6;
    
    
    long long ep1 = sum1 - sum2;
    long long ep2 = sumS1 - sumS2;

    long long newVal = (ep2/ep1) ;

    long long repeating = (ep1 + newVal)/2;
    long long missing = repeating - ep1 ;

    cout << repeating << endl;
    cout << missing << endl;
    
}

int main(){
    
    int n ;
    cin >> n;

    vector<int>  a(n);

    for(auto &i : a) cin >> i;

    // bruteForce(a,n);
    // better(a,n);
    optimal(a,n);
    return 0;
}