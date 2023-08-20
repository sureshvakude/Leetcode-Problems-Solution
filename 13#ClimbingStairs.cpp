/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

#include<bits/stdc++.h>
using namespace std;


int ClimbingStrais(int n,vector<int>& memo){
    if(n<=1) return n;
    if(memo[n]!=0) return memo[n];
    memo[n] = ClimbingStrais(n-1,memo) + ClimbingStrais(n-2,memo);
    return memo[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> memo(50,0);
    cout<<ClimbingStrais(n,memo);

    return 0;
}