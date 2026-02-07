#include <bits/stdc++.h>
using namespace std;
// tc : o(n + nlogn) and sc: O(1)
int main() {
    int n;
    cin >> n;

    vector<int> arrival(n);
    vector<int> departure(n);

    for (int i = 0; i < n; i++) cin >> arrival[i];
    for (int i = 0; i < n; i++) cin >> departure[i];

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0, j = 0;
    int plat = 0, maxPlat = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            plat++;
            maxPlat = max(maxPlat, plat);
            i++;
        } else {
            plat--;
            j++;
        }
    }

    cout << maxPlat;
    return 0;
}
