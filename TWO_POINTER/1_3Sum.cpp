// https://leetcode.com/problems/3sum/

/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // O(N3logM), O(M)
        //  set<vector<int>> st;
        //  int n = nums.size();
        //  for(int i=0;i<n;i++){
        //      for(int j=i+1;j<n;j++){
        //          for(int k=j+1;k<n;k++){
        //              if(nums[i]+nums[j]+nums[k]==0){
        //                  vector<int> ans = {nums[i],nums[j],nums[k]};
        //                  sort(ans.begin(),ans.end());
        //                  st.insert(ans);
        //              }
        //          }
        //      }
        //  }
        //  vector<vector<int>> ans;
        //  for(auto it : st) ans.push_back(it);
        //  return ans;

        // O(N2logm),O(M+N)
        //  unordered_map<int,int> mp;
        //  set<vector<int>> st;
        //  int n = nums.size();
        //  for(auto it : nums)mp[it]++;
        //  for(int i=0;i<n;i++){
        //      if(--mp[nums[i]]==0) mp.erase(nums[i]);
        //      for(int j=i+1;j<n;j++){
        //          if(--mp[nums[j]]==0) mp.erase(nums[j]);
        //          if(mp.find(-nums[i]-nums[j])!=mp.end()){
        //              vector<int> ans = {nums[i],nums[j],-nums[i]-nums[j]};
        //              sort(ans.begin(),ans.end());
        //              st.insert(ans);
        //          }
        //          mp[nums[j]]++;
        //      }
        //      mp[nums[i]]++;
        //  }
        //  vector<vector<int>> ans;
        //  for(auto it :st) ans.push_back(it);
        //  return ans;

        // 2 pointer -> O(N2), O(1)
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (nums[i] != nums[i - 1]))
            {
                int lo = i + 1, hi = n - 1, sum = 0 - nums[i];
                while (lo < hi)
                {
                    if (nums[lo] + nums[hi] == sum)
                    {
                        ans.push_back({nums[lo], nums[hi], nums[i]});
                        while (lo < hi and nums[lo] == nums[lo + 1])
                            lo++;
                        while (lo < hi and nums[hi] == nums[hi - 1])
                            hi--;
                        lo++;
                        hi--;
                    }
                    else if (nums[lo] + nums[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};