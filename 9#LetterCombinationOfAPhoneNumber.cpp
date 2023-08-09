/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include<bits/stdc++.h>
using namespace std;

void findCombination(string digits,string *phoneNumberLetter,int idx,string currString,vector<string>& ans){
    if(digits.length() == currString.length()){
        ans.push_back(currString);
        return;
    }

    string curr = phoneNumberLetter[digits[idx] - '0'];
    for(int i=0;i<curr.length();i++){
        findCombination(digits,phoneNumberLetter,idx+1,currString+curr[i],ans);
    }
}

int main(){
    string digits;
    cin>>digits;

    vector<string> ans;
    if(digits.length() == 0){
        cout<<"[]";
    }

    string phoneNumberLetter[] = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    findCombination(digits,phoneNumberLetter,0,"",ans);
    for(auto a : ans){
        cout<<a<<" ";
    }
    return 0;
}