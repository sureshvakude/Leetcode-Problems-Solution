/*
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 
Constraints:
1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 1){
        return intervals;
    }
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int l=intervals[0][0];
    int r=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=r){
            r = max(r,intervals[i][1]);
        }
        else{
            ans.push_back({l,r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }
    ans.push_back({l,r});
    return ans;
}

int main(){
    return 0;
}