// i < j && a[i] > 2*a[j]
#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){// TC : O(n^2) , SC : O(1)

    int cnt = 0 ; 
    for(int i=0 ; i<n ; i++){

        for(int j=i+1 ; j<n ; j++){

            if(a[i]>2*a[j]) cnt++;
        }
    }
    cout << cnt;
}

// Merge function
void merge(vector<int> &a, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while(left <= mid && right <= high) {
        if(a[left] <= a[right]) temp.push_back(a[left++]);
        else temp.push_back(a[right++]);
    }

    while(left <= mid) temp.push_back(a[left++]);
    while(right <= high) temp.push_back(a[right++]);

    for(int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

// Count reverse pairs
int reversePair(vector<int> &a, int low, int mid, int high) { // O(2n)
    int cnt = 0;
    int right = mid + 1;

    for(int i = low; i <= mid; i++) { // n + n
        while(right <= high && a[i] > 2LL * a[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}

// Optimal merge-sort based solution
int optimal(vector<int> &a, int low, int high) { // TC : O(2nlogn) , SC : O(n)
    if(low >= high) return 0;

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += optimal(a, low, mid);
    cnt += optimal(a, mid + 1, high);
    cnt += reversePair(a, low, mid, high);
    merge(a, low, mid, high);

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    // bruteForce(a,n);
    cout << optimal(a, 0, n - 1);
    return 0;
}
