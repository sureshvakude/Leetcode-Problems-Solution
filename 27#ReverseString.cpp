/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.
*/

#include<bits/stdc++.h>
using namespace std;

void ReverseString(vector<string>& s){
    // In-built function
    // reverse(s.begin(),s.end());

    // without in-built
    int end = s.size() - 1;
    for(int i=0;i<s.size()/2;i++){
        string tp = s[end];
        s[end] = s[i];
        s[i] = tp;
        end--;
    }
}

int main(){
    int n;
    cin>>n;

    vector<string> s;

    for(int i=0;i<n;i++){
        string tp;
        cin>>tp;
        s.push_back(tp);
    }

    ReverseString(s);
    for(auto n : s){
        cout<<n<<" ";
    }
    return 0;
}