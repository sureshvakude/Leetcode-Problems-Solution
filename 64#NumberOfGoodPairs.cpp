/*
Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
        map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.find(nums[i]) != ans.end()){
                ans[nums[i]]++;
            }else{
                ans[nums[i]] = 1;
            }
        }
        int count=0;
        for(auto it = ans.begin(); it!=ans.end(); ++it){
            count += (( it->second * (it->second - 1))/2);
        }
    return count;
}

int main(){
    return 0;
}