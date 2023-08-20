/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2,
 also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Constraints:
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

#include <bits/stdc++.h>
using namespace std;

/*
// BrouteForce approach
string AddTwoString(string str1, string str2){
    if(str1.length() > str2.length()){
        swap(str1,str2);
    }

    string result = "";
    int len1 = str1.length();
    int len2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<len1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    for (int i=len1; i<len2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        result.push_back(carry+'0');
 
    reverse(result.begin(), result.end());
    return result;
}

string MultiplyString(string firstNumber, string secondNumber)
{
    if(firstNumber == "0" || secondNumber == "0") return "0";
    
    int upNumber, downNumber, ans, carry;
    string finalResult = "";
    int n = 0;
    
    for (int i = secondNumber.size() - 1; i >= 0; i--)
    {
        downNumber = secondNumber[i] - '0';
        string eachMultiply(n,'0');
        carry = 0;
        for (int j = firstNumber.size() - 1; j >= 0; j--)
        {
            upNumber = firstNumber[j] - '0';
            ans = (upNumber * downNumber) + carry;
            carry = ans / 10;
            eachMultiply += to_string(ans % 10);
        }
        if (carry > 0)
        {
            eachMultiply += to_string(carry);
        }
        reverse(eachMultiply.begin(),eachMultiply.end());

        finalResult = AddTwoString(finalResult,eachMultiply);
        n++;
    }
    return finalResult;
}
*/

// optimized Solution
 string MultiplyString(string firstNumber, string secondNumber) {
        if (firstNumber == "0" || secondNumber == "0") return "0";
        
        vector<int> res(firstNumber.size()+secondNumber.size(), 0);
        
        for (int i = firstNumber.size()-1; i >= 0; i--) {
            for (int j = secondNumber.size()-1; j >= 0; j--) {
                res[i + j + 1] += (firstNumber[i]-'0') * (secondNumber[j]-'0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        
        int i = 0;
        string ans = "";
        while (res[i] == 0) i++;
        while (i < res.size()) ans += to_string(res[i++]);
        
        return ans;
}

int main()
{
    string firstNumber,secondNumber;
    cin>>firstNumber;
    cin>>secondNumber;

    cout << MultiplyString(firstNumber, secondNumber);
    return 0;
}