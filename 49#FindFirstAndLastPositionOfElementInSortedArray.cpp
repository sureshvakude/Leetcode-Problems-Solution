/*
Given an array of integers nums sorted in non-decreasing order, find the starting 
and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBoundFind(vector<int> nums,int low, int high,int target){
    while(low<=high){
        int mid = low+high >> 1;
        if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

vector<int> SearchRange(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    int startRange = lowerBoundFind(nums, low, high, target);
    int endRange = lowerBoundFind(nums, low, high, target + 1) - 1;
    if(startRange < nums.size() && nums[startRange] == target) return {startRange,endRange};
    return {-1,-1};
}

int main(){
    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;i++){
        int tp;
        cin>>tp;
        nums.push_back(tp);
    }

    int target;
    cin>>target;
    vector<int> ans = SearchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1];
}