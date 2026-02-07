#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& a, int num) {
        int n = a.size(); 
        // Traverse through the array 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
}
void bruteForce(vector<int> &a , int n ){ // O(n^2)
    
    int maxi = 1;
    for(int i=0 ; i<n ; i++){
        
        int x = a[i];
        int cnt = 1;
        
        while (linearSearch(a, x + 1) == true) {
            // Move to the next number in the sequence
            x += 1; 
            // Increment the count of the sequence
            cnt += 1; 
        }

        maxi = max(maxi , cnt);
    }
    cout << maxi;

}

// void better(vector<int> &a , int n ){
//     int maxi = 1;
//     for(int i=0 ; i<n ; i++){

//         set<int> s(a.begin() + i, a.begin() + j + 1);
//         for(int j=i ; j<n ; j++){

//             s.insert(a[j]);
//             int si = s.size();
//             int sum1 =si*(si+1)/2 ;
//             if(sum1 == accumulate(s.begin(),s.end(),0)){
//                 maxi = max(maxi , si);
//             }
//         }

//     }
//     cout << maxi;

// }

void better(vector<int> &a , int n){ // O(nlogn)
    int lastSmaller = INT_MIN;
    int cnt = 0 ;
    int longest = 1 ;

    sort(a.begin(),a.end()); // nlogn

    for(int i=0 ; i<n ; i++){

        if(a[i]-1 == lastSmaller){
            cnt+=1;
            lastSmaller = a[i];
        }
        else if(a[i] != lastSmaller){
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest , cnt);
    }
    cout << longest;
}

void optimal(vector<int> &a , int n){
    int longest = 1;
    unordered_set<int> st;

    for(int i=0 ; i<n ; i++){ // O(n)
        st.insert(a[i]);
    }

    for(auto i : st){ // O(n + 2n)... 2n--> while loop

        if(st.find(i - 1) == st.end()){
            int cnt = 1;
            int x = i;

            while(st.find(x+1) != st.end()){

                x = x+1;
                cnt = cnt+1;

            }
            longest = max(longest,cnt);
        }
    }
    cout << longest;
}
int main(){
    
    int n; 
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i ;

    // bruteForce(arr,n);
    better(arr,n);
    return 0;
}