// https://leetcode.com/problems/subarray-sum-equals-k/description/

// 560. Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0;
        int sum = 0;

        unordered_map<int, int> mp;
        mp[sum] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end())
            {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};