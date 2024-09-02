// https://www.geeksforgeeks.org/problems/subset-sums2234/1
/*
Subset Sums
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> &arr, int n, int ind, int sum, vector<int> &ans)
    {
        if (ind >= n)
        {
            ans.push_back(sum);
            return;
        }
        helper(arr, n, ind + 1, sum, ans);
        helper(arr, n, ind + 1, sum + arr[ind], ans);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        helper(arr, n, 0, 0, ans);
        return ans;
    }
};
