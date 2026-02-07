#include <bits/stdc++.h>
using namespace std;

int main() {
    // key : value .......... Key must be unique
    // map stores unique and sorted elements as {key,value} pair
    // Multi map : same as the map but allowed duplicate keys
    // Unordered  map : same as the map but allowed unordered keys ,, also have unique keys 
    map<int, int> mapp;
    
    mapp[1] = 2;              // {1,2}
    mapp.insert({5, 6});      // {5,6}
    mapp.emplace(2, 4);       // {2,4}   gives sorted keys in output

    map<pair<int, int>, int> mpp;
    mpp[{1, 2}] = 3;          // {{1,2},3}

    cout << mapp[1] << endl;
    cout << mapp[6] << endl; // key not exists then gives 0 as value

    auto i = mapp.find(5);
    cout << i -> second << endl;

    cout << "Normal map:\n";
    for (auto it : mapp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << "\nMap with pair as key:\n";
    for (auto it : mpp) {
        cout << "{" << it.first.first << "," << it.first.second << "} -> " << it.second << endl;
    }

    return 0;
}
