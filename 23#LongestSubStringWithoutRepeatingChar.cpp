/*

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubString(string s)
{

    // This approach work when there is no space in string
    // if(s.length() == 0) return 0;
    // unordered_set<char> ans;
    // int count = 0;
    // for(int i=0;i<s.length();i++){
    //     if(ans.find(s[i]) == ans.end()){
    //         ans.insert(s[i]);
    //         continue;
    //     }
    //     if(count < ans.size()){
    //         count = ans.size();
    //         ans.erase(ans.begin(),ans.end());
    //         ans.insert(s[i]);
    //     }
    // }
    // return count;

    // This will work on all case
    if (s.length() == 0)
        return 0;
    unordered_map<char, int> m;
    int i = 0, j = 0, ans = INT_MIN;
    while (j < s.length())
    {
        m[s[j]]++;
        if (m.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
        }
        else if (m.size() < j - i + 1)
        {
            while (m.size() < j - i + 1)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;

    cout << LongestSubString(s);
    return 0;
}