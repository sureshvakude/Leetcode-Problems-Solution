/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically 
using all the original letters exactly once.

 

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 
Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> GroupAnagrams(vector<string>& strs) {
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    for(auto str : strs){
        string temp = str;
        sort(str.begin(), str.end());
        if(mp[str])
        {
            ans[mp[str]-1].push_back(temp);
        }
        else{
            ans.push_back({temp});
            mp[str]=ans.size();
        }
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = GroupAnagrams(strs);
    for(auto str : ans){
        for(auto s : str){
            cout<<s<<" ";
        }
        cout<<"\n";
    }
    return 0;
}