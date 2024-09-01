// https://leetcode.com/problems/4sum/description/
/*
19. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // set<vector<int>> st;
        // for(int i=0;i<n-3;i++){
        //     for(int j=i+1;j<n-2;j++){
        //         for(int k=j+1;k<n-1;k++){
        //             long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
        //             if(newTarget<INT_MIN || newTarget>INT_MAX) continue;
        //             if(binary_search(nums.begin()+k+1,nums.end(),(int)newTarget)){
        //                 st.insert({nums[i],nums[j],nums[k],(int)newTarget});
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto it : st) ans.push_back(it);
        // return ans;

        // Two Pointer Approach
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right and nums[left] == nums[left + 1])
                            left++;
                        while (left < right and nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};