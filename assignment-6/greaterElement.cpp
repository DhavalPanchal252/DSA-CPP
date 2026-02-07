#include <bits/stdc++.h>
using namespace std;
// TC :O(n1+n2) and SC : O(n2)
int main() {
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    unordered_map<int, int> nextGreater;
    stack<int> st;

    // Traverse nums2 to find the next greater element for each
    for (int num : nums2) {
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // Remaining elements have no next greater
    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    // Output results for nums1
    for (int i = 0; i < n1; i++) {
        cout << nextGreater[nums1[i]];
        if (i != n1 - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
