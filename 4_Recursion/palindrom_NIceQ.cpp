#include <bits/stdc++.h>
using namespace std;
/*
remove_if(...)
This doesn’t erase, it just moves the unwanted stuff to the end and returns an iterator to the new end.
            dhavalsdssd********
                       ^
                    then new end 
s.begin(), s.end() → go through the full string

[](char c) { return !isalpha(c); } → this is a lambda (like a mini function).

s.erase(new end, s.end())
It cleans out the junk from the string — removes everything from the new "valid end" to the actual end.
*/
bool isPalindrome(string s){
    for(auto &c : s){ 
        tolower(c);
    }
    s.erase(remove_if(s.begin(),s.end(),[](char c){
            return !isalnum(c);}),s.end());
    cout << "After removing non char : " << s;

    string rev = s;
    reverse(s.begin(),s.end());

    return rev==s;
}
int main(){
    string s;
    // cin >> s; this stops when space arrise
    getline(cin, s);  //  reads full input line including spaces
    cout << "Input : " << s << endl;
    
    if(isPalindrome(s)) cout << endl << "Palindrom";
    else cout << endl << "Not Palindrom";
    return 0;
}