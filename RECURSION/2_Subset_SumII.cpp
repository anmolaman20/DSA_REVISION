// https://leetcode.com/problems/subsets-ii/
/*
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<vector<int>> st;
    void helper(vector<int> &nums, int ind, int n, vector<int> temp)
    {
        if (ind >= n)
        {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        helper(nums, ind + 1, n, temp);
        temp.pop_back();
        helper(nums, ind + 1, n, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        helper(nums, 0, n, {});
        vector<vector<int>> ans;
        for (auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};