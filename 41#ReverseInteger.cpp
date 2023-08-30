/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
 
Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include<bits/stdc++.h>
using namespace std;

int Reverse(int x){
    long int duplicateX = abs(x);
    long int rev = 0;
    while(duplicateX > 0){
        rev = (rev * 10) + (duplicateX % 10);
        duplicateX /= 10;
    }
    if(x < 0) rev *= (-1);
    if(rev > INT_MAX || rev < INT_MIN) return 0;
    return rev;
}

int main(){
    int x;
    cin>>x;
    cout<<Reverse(x);
    return 0;
}