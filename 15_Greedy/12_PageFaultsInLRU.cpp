#include <bits/stdc++.h>
using namespace std;

/*
Page Faults in LRU

Given:
N = number of page requests
C = cache capacity
pages[] = sequence of page requests

If a page is not present in cache,
a page fault occurs.

When the cache is full, remove the
Least Recently Used (LRU) page.

Return the total number of page faults.
*/


/*
TC : O(N)
SC : O(C)
*/
int pageFaults(int N, int C, int pages[]) {

    list<int> lru;

    // list<int>::iterator -> Iterator pointing to that page in the list
    unordered_map<int, list<int>::iterator> mp;

    int faults = 0;

    for(int i = 0; i < N; i++) {

        int page = pages[i];

        // Page not present in cache
        if(mp.find(page) == mp.end()) {

            faults++;

            // Cache full
            if(lru.size() == C) {

                int lruPage = lru.back();

                lru.pop_back();

                mp.erase(lruPage);
            }

            lru.push_front(page);

            mp[page] = lru.begin();
        }
        else {

            // Move page to front
            lru.erase(mp[page]);

            lru.push_front(page);

            mp[page] = lru.begin();
        }
    }

    return faults;
}

int main() {

    int N, C;
    cin >> N >> C;

    int pages[N];

    for(int i = 0; i < N; i++) {
        cin >> pages[i];
    }

    cout << pageFaults(N, C, pages);

    return 0;
}