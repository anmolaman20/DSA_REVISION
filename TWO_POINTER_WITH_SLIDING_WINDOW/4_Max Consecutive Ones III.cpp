//  https://leetcode.com/problems/max-consecutive-ones-iii/description/

/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        // O(N+N)

        // int l = 0, r = 0, max_len = 0, cnt0 = 0, n = nums.size();
        // while (r < n)
        // {
        //     if (!nums[r])
        //         cnt0++;
        //     while (cnt0 > k)
        //     {
        //         if (!nums[l])
        //         {
        //             cnt0--;
        //         }
        //         l++;
        //     }
        //     max_len = max(max_len, r - l + 1);
        //     r++;
        // }
        // return max_len;

        // O(N)

        int l = 0, r = 0, max_len = 0, cnt0 = 0, n = nums.size();
        int prev0cnt = 0;
        while (r < n)
        {
            if (!nums[r])
                cnt0++;
            if (cnt0 > k)
            {
                if (!nums[l])
                {
                    cnt0--;
                }
                l++;
            }
            if (cnt0 <= k)
                max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};