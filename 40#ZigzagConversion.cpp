/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
 
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
 
Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

string ZigzagConvert(string s, int norows){
    vector<string> ans(norows,"");
    int j=0, swit = -1;
    for(int i=0; i<s.size(); i++){
        if(j == 0 || j == norows - 1) swit *= (-1);
        ans[j] += s[i];
        if(swit == 1) j++;
        else j--;
    }

    string result;
    for(auto s : ans) result+=s;
    return result;
}

int main(){
    string s;
    cin>>s;

    int norows;
    cin>>norows;

    cout<<ZigzagConvert(s,norows);
    return 0;
}