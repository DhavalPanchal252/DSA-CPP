#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){// TC : O(n^2) , SC : O(1)

    long long maxProduct = INT_MIN;
    for(int i=0 ; i<n ; i++){

        long long product = 1;
        for(int j=i ; j<n ; j++){
            product *= a[j];
            maxProduct = max(maxProduct,product);
        }

    }

    cout << maxProduct;
}

void optimal(vector<int> &a , int n){// TC : O(n) , SC : O(1)

    int maxProduct = INT_MIN;
    int prefix = 1 , suffix =1 ;

    for(int i=0 ; i<n ; i++){

        if(prefix == 0) prefix = 1 ;
        if(suffix == 0) suffix = 1 ;

        prefix *= a[i];

        suffix *= a[n-i-1];

        maxProduct = max(maxProduct , max(prefix,suffix));

    }
    cout << maxProduct;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    // bruteForce(a,n);
    optimal(a,n);
    return 0;
}
