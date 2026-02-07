#include <bits/stdc++.h>
using namespace std;
// TC : O(n + m) : SC : O(n + m)
void bruteForce(vector<int> &a1 , vector<int> &a2 ,int n ,int m){
    int left = 0 ; 
    int right = 0 ;
    vector<int> ans;

    while(left < n && right < m){
        if(a1[left] <= a2[right]){
            ans.push_back(a1[left]);
            left++;
        }
        else{
            ans.push_back(a2[right]);
            right++;
        }
    }
    while(left<n){
        ans.push_back(a1[left]);
        left++;
    }
    while(right<m){
        ans.push_back(a2[right]);
        right++;
    }

    int index = n+m;
    double mid;
    if(index%2 == 0){
        mid = (ans[index/2] + ans[(index/2)-1])/2.0;
    }
    else{
        mid = ans[index/2];
    }

    cout << mid;

}

// TC : O(n + m) : SC : O(1)
void better(vector<int> &a1 , vector<int> &a2 ,int n ,int m){
    int ele1 = -1 , ele2 = -1;
    int index = n+m;
    int index2 = index/2;
    int index1 = index2-1;
    int cnt = 0;
    int left = 0 , right = 0;

    while(left < n && right < m){
        if(a1[left] <= a2[right]){
            if(cnt == index1) ele1 = a1[left];
            if(cnt == index2) ele2 = a1[left];
            cnt++;
            left++;
            
        }
        else{
            if(cnt == index1) ele1 = a2[right];
            if(cnt == index2) ele2 = a2[right];
            cnt++;
            right++;
        }
    }
    while(left<n){
        if(cnt == index1) ele1 = a1[left];
        if(cnt == index2) ele2 = a1[left];
        cnt++;
        left++;
    }
    while(right<m){
        if(cnt == index1) ele1 = a2[right];
        if(cnt == index2) ele2 = a2[right];
        cnt++;
        right++;
    }

    double mid;
    if(index%2 == 0){
        mid = (ele1 + ele2)/2.0;
    }
    else{
        mid = ele2;
    }
    cout << mid;
}

// TC : O(log(min(n,m))) , SC : O(1)
double optimal(vector<int> &a1, vector<int> &a2, int n, int m){

    if(n > m) return optimal(a2, a1, m, n);

    int low = 0, high = n;
    int total = n + m;
    int left = (total + 1) / 2;

    while(low <= high){

        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, r1 = INT_MAX;
        int l2 = INT_MIN, r2 = INT_MAX;

        if(mid1 < n) r1 = a1[mid1];
        if(mid1 - 1 >= 0) l1 = a1[mid1 - 1];

        if(mid2 < m) r2 = a2[mid2];
        if(mid2 - 1 >= 0) l2 = a2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            if(total % 2 == 1)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return 0.0; // unreachable
}

int main(){
    
    int n,m;
    cin >> n >> m;

    vector<int> a1(n);
    vector<int> a2(m);

    for(auto &i : a1) cin >> i;
    for(auto &i : a2) cin >> i;

    // bruteForce(a1 ,a2 ,n ,m);
    // better(a1 ,a2 ,n ,m);
    cout << optimal(a1 ,a2 ,n ,m);
    return 0;
}