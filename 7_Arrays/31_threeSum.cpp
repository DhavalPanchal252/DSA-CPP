#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &nums , int n){ // TC : O(n^3) and SC : O(2 * no. of the unique triplets)

    set<vector<int>> s;
    for(int i=0 ; i<n-2 ; i++){
        for(int j = i+1 ; j < n-1 ; j++){
            for(int k = j+1 ; k < n ; k++){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    vector <int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
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

void better(vector<int> &nums , int n){// TC : O(n^2) and SC : O(2 * no. of the unique triplets)

    set<vector<int>> s;
    
    for(int i=0 ; i<n-2 ; i++){
        unordered_set<int> hash; // O(1)
        for(int j = i+1 ; j < n-1 ; j++){
            
            int target = -(nums[i] + nums[j]);
            if(hash.find(target) != hash.end()){

                vector <int> temp = {nums[i],nums[j],target};
                sort(temp.begin(),temp.end());
                s.insert(temp);
            }
        
            hash.insert(nums[j]);
            
            
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

// TC : O(n^2) and SC : O(no of triplets)
void optimal(vector<int> &nums , int n){

    sort(nums.begin(),nums.end());

    vector<vector<int>> result;
    for(int i =0 ; i<n ; i++){

        if(i>0 && nums[i] == nums[i-1]) continue;

        int j = i+1 ;
        int k = n-1 ;

        while(j<k){
            
            int sum = nums[i]+nums[j]+nums[k];

            if(sum == 0){
                result.push_back({nums[i],nums[j],nums[k]});

                j++;
                k--;

                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k--;
            }
            else if(sum < 0 ) j++;
            else k--;
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

    // bruteForce(arr , n);
    // better(arr , n);
    optimal(arr , n);
    return 0;
}