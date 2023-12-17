/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same character, 
but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
 
Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/

#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char,char> Smap, Tmap;
    for(int i=0; i<s.size(); i++){
        if(Smap[s[i]] && Smap[s[i]]!=t[i]) return false;
        if(Tmap[t[i]] && Tmap[t[i]]!=s[i]) return false;
        Smap[s[i]] = t[i];
        Tmap[t[i]] = s[i];
    }   
    return true;
}

int main(){
    return 0;
}