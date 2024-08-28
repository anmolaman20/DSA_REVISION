//  https://leetcode.com/problems/binary-subarrays-with-sum/
/*
930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
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
        while (r < n)
        {
            sum += arr[r];
            while (sum > k)
            {
                sum -= arr[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &arr, int k)
    {
        int n = arr.size();
        int countWithSumLEK = countSubarraysWithSumLE(arr, n, k);
        int countWithSumLEKMinus1 = countSubarraysWithSumLE(arr, n, k - 1);
        return countWithSumLEK - countWithSumLEKMinus1;
    }
};