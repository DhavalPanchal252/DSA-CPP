#include <bits/stdc++.h>
using namespace std;
/*
Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.

Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}
*/
void bruteforce(vector<int> a1,vector<int> a2)
{
    int n1 = a1.size();
    int n2 = a2.size();

    set<int> s;

    for(int i=0 ; i < n1 ; i++){
        s.insert(a1[i]);
    }
    
    for(int i=0 ; i < n2 ; i++){
        s.insert(a2[i]);
    }

    for(auto &i : s){
        cout << i << " ";
    }
}

void optimal(vector<int> a1 , vector<int> a2)
{
    int n1 = a1.size();
    int n2 = a2.size();
    int i =0;
    int j =0;
    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(a1[i] <= a2[j]){
            if(unionArr.size() == 0 || unionArr.back() != a1[i]){
                unionArr.push_back(a1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != a2[j]){
                unionArr.push_back(a2[j]);
            }
            j++; 
        }
    }
    while(i<n1){
        if(unionArr.size() == 0 || unionArr.back() != a1[i]){
            unionArr.push_back(a1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionArr.size() == 0 || unionArr.back() != a2[j]){
            unionArr.push_back(a2[j]);
        }
        j++;
    }

    for(auto &i : unionArr){
        cout << i << " ";
    }
}

int main(){

    int n1;
    cin >> n1;
    vector<int> a1(n1);
    for(auto &i : a1){
        cin >> i;
    }

    int n2;
    cin >> n2;
    vector<int> a2(n2);
    for(auto &i : a2){
        cin >> i;
    }

    // bruteforce(a1,a2);

    optimal(a1,a2);
    return 0;
}
