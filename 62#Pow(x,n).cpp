/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 
Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long int k=abs(n);
    double ans=1.0;
    if(n==0) return 1.0;
    if(x==1.0) return x;
    while(k>0)
    {
        if(k%2){ ans=ans*x; k--;}
        else{ x=x*x; k=k/2;}
    }
    if(n<0)
    {
        double p=(double)(1.0)/(double)(ans);
        return p;
    }
    return ans;
}

int main(){
    double x;
    int n;
    cin>>x>>n;
    cout<<myPow(x,n);
    return 0;
}