#include <bits/stdc++.h>
using namespace std;

// TC : O(n^4) and SC : O(2 * no. of the unique triplets)
void bruteForce(vector<int> &nums , int n , int target){

    sort(nums.begin(),nums.end());

    set<vector<int>> s;
    for(int i=0 ; i< n-3 ; i++){
        for(int j = i+1 ; j < n-2 ; j++){
            for(int k = j+1 ; k < n-1 ; k++){
                for(int l = k+1 ; l < n ; l++){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                    }
                }
                
            }
        }   
    }

    vector<vector <int>> result(s.begin(),s.end());

    for(auto &i : result){
        for(auto &k : i){
            cout << k << " ";
        }
        cout << endl;
    }
}

// TC : O(n^3) and SC : O(2 * no. of the unique triplets)
void better(vector<int> &nums , int n , int target){
    set<vector<int>> s;

    for(int i=0 ; i< n-2 ; i++){
        for(int j = i+1 ; j < n-1 ; j++){

            unordered_set<int> hash;

            for(int k = j+1 ; k < n ; k++){
                
                int other = target -( nums[i] + nums[j] + nums[k] );
                
                if(hash.find(other) != hash.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],other};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hash.insert(nums[k]);
            }
        }   
    }

    vector<vector <int>> result(s.begin(),s.end());

    for(auto &i : result){
        for(auto &k : i){
            cout << k << " ";
        }
        cout << endl;
    }
}

// TC : O(n^3) and SC : O(no of triplets)
void optimal(vector<int> &nums , int n , int target){

    long long t = target;

    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for(int i = 0; i < n; i++) {

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        for(int j = i + 1; j < n; j++) {

            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            int k = j + 1, l = n - 1;

            while(k < l) {

                long long sum = 1LL*nums[i] + nums[j] + nums[k] + nums[l];

                if(sum == t) {
                    result.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; 
                    l--;

                    while(k < l && nums[k] == nums[k - 1]) k++;
                    while(k < l && nums[l] == nums[l + 1]) l--;
                }
                else if(sum < t) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }

    for(auto &i : result){
        for(auto &k : i){
            cout << k << " ";
        }
        cout << endl;
    }
}

int main(){
    
    int n ; 
    cin >> n;
    
    vector<int> arr(n);
    
    for(auto &i : arr){
        cin >> i ;
    }

    int target ;
    cin >> target;
    
    // bruteForce(arr , n , target);
    // better(arr , n , target);
    better(arr , n , target);

    return 0;
}