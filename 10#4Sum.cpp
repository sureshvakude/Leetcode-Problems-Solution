/*
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include<bits/stdc++.h>
using namespace std;

void AllUniqueQuadruplets(vector<int>& nums, int target, vector<vector<int>>& ans){
    sort(nums.begin(),nums.end());
    int size = nums.size();
    for(int i=0;i<size;i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        for(int j=i+1;j<size;j++){
            if(j!=(i+1) && nums[j] == nums[j-1]){
                continue;
            }
            int k = j+1;
            int l = size-1;
            while(k<l){
                long long sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum == target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]){
                    k++;
                    }
                    while(k<l && nums[l]==nums[l+1]){
                        l--;
                    }
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;    
                }
            }
        }
    }
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

    vector<vector<int>> ans;
    AllUniqueQuadruplets(nums,target,ans);
    for(auto a : ans){
        for(auto value : a){
            cout<<value<<" ";
        }
        cout<<"\n";
    }
    return 0;
}