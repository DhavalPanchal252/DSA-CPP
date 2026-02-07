#include <bits/stdc++.h>
using namespace std;
/*
🧠 How it works:
Let’s say i = 3

👉 If 12 % 3 == 0, that means:

✅ 3 is a divisor
✅ And so is 12 / 3 = 4
So we push both: 3 and 4

❗ But what if i == n / i?
That happens when n is a perfect square.
Example: n = 36, and i = 6
→ n / i = 6 also

So we don't want to push 6 twice 🔁

Hence this condition:
if (i != n / i)
is used to avoid duplicate entries when i and n/i are the same.
*/
vector<int> div(int n){

    vector<int> divisors;
    int sqt = sqrt(n);

    for(int i=1 ; i <= sqt ; i++){

        if(n%i == 0){
            divisors.push_back(i);

            if(i != n/i) divisors.push_back(n/i);
        }
    }

    return divisors;
}

int main(){
    int n;
    cin >> n;

    vector<int> divisors = div(n);

    sort(divisors.begin(),divisors.end()); // otherwise it gives unsorted output

    for(int i : divisors)
    {
        cout << i << " ";
    }
    return 0;
}