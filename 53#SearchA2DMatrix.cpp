/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

#include<bits/stdc++.h>
using namespace std;

bool SearchTarget(vector<vector<int>>& mat, int target){
    
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int tp;
            cin>>tp;
            mat.emplace_back(tp);
        }
    }
    int target;
    cin>>target;

    cout<<SearchTarget(mat,target);
    return 0;
}