/*

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different
 word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 
Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/

#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
      
    vector<int> sCharCount(26,0);
    vector<int> tCharCount(26,0);

    for (char c : s) sCharCount[c - 'a']++;
      
    for (char c : t) tCharCount[c - 'a']++;
    
    for (int i = 0; i < 26; i++) {
        if (sCharCount[i] != tCharCount[i]) return false;
    }
        
    return true;
}

int main(){
    return 0;
}