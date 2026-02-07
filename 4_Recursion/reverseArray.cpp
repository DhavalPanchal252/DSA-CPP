#include <bits/stdc++.h>
using namespace std;

void reverseA(vector<int> &a){
    int low=0;
    int high=a.size()-1;

    while(low<high){
        swap(a[low],a[high]);
        low++;
        high--;
    }
    for(auto i : a){
        cout << i << " ";
    }
}
//or
void rev(vector<int> &a){

    reverse(a.begin(),a.end());

    for(auto i : a){
        cout << i << " ";
    }
}
int main(){
 
    vector<int> arr1 = {1,2,3,4,5};
    reverseA(arr1);
    
    cout << endl;
    vector<int> arr2 = {1,2,3,4,5};
    rev(arr2);
    return 0;
}