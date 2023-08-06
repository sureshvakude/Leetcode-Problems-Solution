/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

/*
//-------------------recursive function appproach---------------------------

#include <bits/stdc++.h>
using namespace std;

void Find3Sum(vector<int> &arr, int i, int j, int k, int n, set<vector<int>> &ans)
{
      if (i == n - 1) return;
      if (arr[i] + arr[j] + arr[k] == 0){
            ans.insert({arr[i],arr[j],arr[k]});
      }
      if (k == n && j == n - 1){
            i++;
            j = i + 1;
            k = j + 1;
      }
      else if (k == n){
            j++;
            k = j + 1;
      }else{ 
            k++; 
      }
      Find3Sum(arr, i, j, k, n, ans);
}

int main()
{
      int n;
      cin>>n;

      vector<int> nums;
      for(int i=0;i<n;i++){
            int tp=0;
            cin>>tp;
            nums.push_back(tp);
      }

      sort(nums.begin(),nums.end());

      set<vector<int>> ans;
      Find3Sum(nums,0,1,2,nums.size()-1,ans);

      for(auto num : ans){
            for(int n : num){
                  cout<<n<<" ";
            }
            cout<<"\n";
      }
      return 0;
}
*/

// iterative approach

#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin>>n;

      vector<int> nums;
      for(int i=0;i<n;i++){
            int tp=0;
            cin>>tp;
            nums.push_back(tp);
      }
      sort(nums.begin(),nums.end());
      set<vector<int>> ans;
      
      for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1; 
            while(j<k){
                  int sum = nums[i]+nums[j]+nums[k];
                  if(sum == 0){
                        ans.insert({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                  } else if (sum < 0) {
                        j++;
                  } else {
                        k--;
                  }
            }
      }

      for(auto num : ans){
            for(int n : num){
                  cout<<n<<" ";
            }
            cout<<"\n";
      }
      return 0;
}