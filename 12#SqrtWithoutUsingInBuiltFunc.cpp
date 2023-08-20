/*

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

Constraints:
0 <= x <= 231 - 1

*/

#include<bits/stdc++.h>
using namespace std;

int SqrtFun(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int low = 0;
        int high = n;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (n == mid*mid) return mid;
            else if (n > mid*mid){
                if (n < (mid + 1) * (mid + 1)) return mid;
                else low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return mid;
    }

int main(){
    int n;
    cin>>n;

    cout<<SqrtFun(n);
    return 0;
}