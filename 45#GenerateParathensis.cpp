/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 
Constraints:
1 <= n <= 8
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int open, int close, vector<string> &ans, string s){
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        solve(open-1, close, ans, s);
        s.pop_back();
    }
    if(close>open){
        s.push_back(')');
        solve(open, close-1, ans, s);
        s.pop_back();
    }
}

vector<string> GenerateParenthesis(int n) {
    vector<string> ans;
    int open=n;
    int close=n;
    string s="";
    solve(open, close, ans, s);
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> ans = GenerateParenthesis(n);
    return 0;
}