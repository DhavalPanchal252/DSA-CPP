#include<bits/stdc++.h>
using namespace std;

// Helper function to calculate sum across the middle
long long crossingSum(vector<int>& arr, int low, int mid, int high) {
    long long sum = 0, leftSum = LLONG_MIN, rightSum = LLONG_MIN;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

// Divide and Conquer function
long long maxSubArray(vector<int> &arr, int low, int high) {
    if (low == high) return arr[low];  // base case

    int mid = (low + high) / 2;

    long long leftAns = maxSubArray(arr, low, mid);
    long long rightAns = maxSubArray(arr, mid + 1, high);
    long long crossAns = crossingSum(arr, low, mid, high);

    return max({leftAns, rightAns, crossAns});
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << maxSubArray(arr, 0, n - 1) << endl;
    return 0;
}
