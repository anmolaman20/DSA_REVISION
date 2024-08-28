// https://leetcode.com/problems/subarrays-with-k-different-integers/

/*
992. Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarraysWithSumLE(vector<int> arr, int n, int k)
    {
        if (k < 0)
            return 0;
        int l = 0, r = 0, sum = 0, count = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[arr[r]]++;
            while (mp.size() > k)
            {
                if (--mp[arr[l]] == 0)
                {
                    mp.erase(arr[l]);
                }
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int> &arr, int k)
    {
        int n = arr.size();
        int countWithSumLEK = countSubarraysWithSumLE(arr, n, k);
        int countWithSumLEKMinus1 = countSubarraysWithSumLE(arr, n, k - 1);
        return countWithSumLEK - countWithSumLEKMinus1;
    }
};