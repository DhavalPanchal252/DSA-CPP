#include <bits/stdc++.h>
using namespace std;

int main() {
    // Everything is same as set
    // Only stores duplicate elements also

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    cout << "Before erase:\n";
    for(auto it : ms) {
        cout << it << " ";
    }
    cout << endl;

    ms.erase(1); // ❗ this will erase all 1s

    cout << "After erase:\n";
    for(auto it : ms) {
        cout << it << " ";
    }
    cout << endl;

    // Adding more 1s to try erase one-by-one
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    cout << "After reinserting 1s:\n";
    for(auto it : ms) {
        cout << it << " ";
    }
    cout << endl;

    // Only one 1 will be erased
    auto it = ms.find(1);
    if (it != ms.end())
        ms.erase(it);

    cout << "After erasing one 1:\n";
    for(auto it : ms) {
        cout << it << " ";
    }
    cout << endl;

    // ❌ You can't do +2 with multiset iterator like ms.find(1)+2
    // 👉 So use std::next
    auto first = ms.find(1);
    auto last = std::next(first, 2); // move 2 steps ahead
    ms.erase(first, last);

    cout << "After erasing 2 more 1s:\n";
    for(auto it : ms) {
        cout << it << " ";
    }
    cout << endl;

    // rest all functions are same
    return 0;
}
