/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <iostream>
using namespace std;

int main()
{
    string str1 = "helloworldheli";
    string str2 = "heliu";
    bool flag = false;
    int startindex = -1;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == str2[0])
        {
            int tp = i + 1, j = 1;
            while (str2[j] != NULL && str1[tp] != NULL)
            {
                if (str1[tp] == str2[j])
                {
                    tp++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            if (tp == i + str2.length())
            {
                flag = true;
                startindex = i;
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << startindex;
    return 0;
}