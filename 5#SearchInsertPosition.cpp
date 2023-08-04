/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/
#include <bits/stdc++.h>
using namespace std;

int searchTargetNumber(vector<int> &nums, int target)
{
    int size = nums.size();

    if (target > nums[size - 1]) return size;

    int lidx = 0, ridx = size - 1;
    while (lidx < ridx)
    {
        int mid = lidx + (ridx - lidx) / 2;

        if (nums[mid] >= target)
        {
            ridx = mid;
        }
        else
        {
            lidx = mid + 1;
        }
    }
    return lidx;
}

int main()
{

    int n;
    cin >> n;

    vector<int> numberArray;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numberArray.emplace_back(temp);
    }

    int target;
    cin >> target;

    cout << searchTargetNumber(numberArray, target);
    return 0;
}