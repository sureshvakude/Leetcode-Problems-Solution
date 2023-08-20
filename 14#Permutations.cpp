/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include<bits/stdc++.h>
using namespace std;

void Permutations(int idx,vector<int> nums, vector<vector<int>>& ans){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        Permutations(idx+1,nums,ans);
        swap(nums[idx],nums[i]);
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;i++){
        int tp;
        cin>>tp;
        nums.emplace_back(tp);
    }
    vector<vector<int>> ans;
    Permutations(0,nums,ans);
    for(auto num : ans){
        for(auto n : num){
            cout<<n<<" ";
        }
        cout<<"\n";
    }
    return 0;
}