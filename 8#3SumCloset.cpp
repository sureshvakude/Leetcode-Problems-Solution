/*
Given an integer array nums of length n and an integer target, find three integers in nums such that 
the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include<bits/stdc++.h>
using namespace std;

int NearSum(vector<int>& arr,int target){
      sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i=0; i<arr.size()-2;i++){
            int l= i+1, r = arr.size()-1;
            while(l<r){
                int sum = arr[i]+arr[l]+arr[r];
                diff = abs(diff-target)>abs(sum-target) ? sum : diff;
                if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return diff;
}

int main(){
      int n;
      cin>>n;

      vector<int> arr;
      for(int i=0;i<n;i++){
            int tp;
            cin>>tp;
            arr.emplace_back(tp);
      }
      int target;
      cin>>target;
      cout<<NearSum(arr,target);

      return 0;
}