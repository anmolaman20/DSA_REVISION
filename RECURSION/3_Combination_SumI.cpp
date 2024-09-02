// https://leetcode.com/problems/combination-sum/description/

/*
39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(vector<int> &nums, int tar, int ind, vector<int> temp, vector<vector<int>> &ans, int n)
    {
        if (tar < 0)
            return;
        if (ind >= n)
        {
            if (tar == 0)
            {
                ans.push_back(temp);
                return;
            }
            return;
        }
        if (nums[ind] <= tar)
        {
            temp.push_back(nums[ind]);
            helper(nums, tar - nums[ind], ind, temp, ans, n);
            temp.pop_back();
            helper(nums, tar, ind + 1, temp, ans, n);
        }
        else
        {
            helper(nums, tar, ind + 1, temp, ans, n);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int tar)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        helper(nums, tar, 0, {}, ans, n);
        return ans;
    }
};