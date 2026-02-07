#include <bits/stdc++.h>
#include <openssl/sha.h>
using namespace std;

// Function to compute SHA256 hash of a string
string sha256(const string &data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)data.c_str(), data.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str(); 
}

// Hash two strings together (double SHA256)
string hash2(const string &a, const string &b) {
    string combined = a + b;
    string first = sha256(combined);
    return sha256(first);
}

// Recursive function to compute Merkle root
string merkle(vector<string> hashes) {
    int round = 1;
    while (hashes.size() > 1) {
        cout << "\nRound " << round++ << " - Number of branches: " << hashes.size() << "\n";
        vector<string> newHashList;

        for (size_t i = 0; i < hashes.size(); i += 2) {
            if (i + 1 < hashes.size()) {
                cout << "Hashing pair: " << hashes[i].substr(0, 8)
                     << " + " << hashes[i + 1].substr(0, 8) << endl;
                newHashList.push_back(hash2(hashes[i], hashes[i + 1]));
            } else {
                cout << "Odd one out: " << hashes[i].substr(0, 8)
                     << " -> hashing it with itself\n";
                newHashList.push_back(hash2(hashes[i], hashes[i]));
            }
        }

        hashes = newHashList;
    }

    cout << "\n✅ Merkle Root: " << hashes[0] << endl;
    return hashes[0];
}

int main() {
    vector<string> txHashes = {
        "aa", "bb", "cc", "dd", "ee", "11", "22", "33", "44", "55"
    };

    // Convert short hex strings into full hashes (for demo)
    for (auto &h : txHashes) {
        h = sha256(h);
    }

    merkle(txHashes);
    return 0;
}
