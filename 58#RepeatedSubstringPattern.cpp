/*
Given a string s, check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together.

Example 1:
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.

Example 2:
Input: s = "aba"
Output: false

Example 3:
Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
 
Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string doubled = s + s;
    string sub = doubled.substr(1, doubled.size() - 2);
    return sub.find(s) != string::npos;
}

int main(){
    return 0;
}