#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
*/
int helper(vector<int> &a , int maxPages){ 
    int cnt = 1;
    int sum = 0 ;
    for(int i=0 ; i<a.size() ; i++){
        if(sum+a[i] <= maxPages){
            sum += a[i];
        }
        else{
            cnt++;
            sum = a[i];
        }
    }
    return cnt;
}
// TC : O((sum - max)*n)

int bruteForce(vector<int> &a, int m){ 

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);
    for(int i=low ; i<=high ; i++){
        
        if(helper(a,i) == m) return i ;
    }
    return -1;
}

// TC : O(logn(sum - max)*n)

int optimal(vector<int> &a, int m){
    int n = a.size();
    if(m>n) return -1; 

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0); 

    while(low<=high){
        int mid = low + (high-low)/2;

        int student = helper(a,mid);
        if(student > m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){

    int n ,m;
    cin >> n >> m;
    
    vector<int> a(n);
    

    for(auto &i : a) cin >> i;

    // cout << bruteForce(a,m);
    cout << optimal(a,m);

    return 0;
}
