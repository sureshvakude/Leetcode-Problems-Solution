/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Examples : 

Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints: 
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++)
    {
        string tp;
        cin>>tp;
        arr.push_back(tp);
    }

    sort(arr.begin(),arr.end());
    string first=arr[0],last = arr[n-1];
    string ans="";
    for(int i=0;i<min(first.size(),last.size());i++)
    {
        if(first[i]!=last[i])
        {
            break;
        }
        else
        {
        ans+=first[i];
        }
    }
    cout<<ans;
    return 0;
}