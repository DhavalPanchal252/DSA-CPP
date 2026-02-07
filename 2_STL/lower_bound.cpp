#include <bits/stdc++.h>
using namespace std;

// lower bound : x <= key then return key index
// upper bound : x > key then return key index
/*
| x | `lower_bound(x)` | `upper_bound(x)` |
| - | ---------------- | ---------------- |
| 2 | 2                | 3                |
| 4 | 4                | 5                |
| 5 | 5                | Not found        |
| 7 | Not found        | Not found        |
*/
int main() {
    set<int> s = {1, 2, 3, 4, 5};

    auto i = s.lower_bound(3); // 3

    if (i != s.end())
        cout << *i << endl;  
    else
        cout << "Not found\n";


    auto it = s.upper_bound(1);
    if (it != s.end())
        cout << *it << endl;  
    else
        cout << "Not found" << endl;

    return 0;
}
