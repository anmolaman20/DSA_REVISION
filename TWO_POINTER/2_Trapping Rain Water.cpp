// https://leetcode.com/problems/trapping-rain-water/description/
/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &nums)
    {
        // O(N2), O(1)
        //  int ans = 0;
        //  int n = nums.size();
        //  for(int i=0;i<n;i++){
        //      int maxRight = nums[i], maxLeft = nums[i];
        //      //lets find leftMax
        //      for(int k=0;k<i;k++){
        //          maxLeft = max(maxLeft,nums[k]);
        //      }

        //     //lets find maxRight
        //     for(int k=i+1;k<n;k++){
        //         maxRight = max(maxRight,nums[k]);
        //     }

        //     // cout<<maxLeft<<" "<<maxRight<<endl;
        //     ans += (min(maxRight,maxLeft)-nums[i]);
        // }
        // return ans;

        // O(3N),O(2N)
        //  int n = nums.size();
        //  vector<int>left(n);
        //  vector<int>right(n);
        //  int ans = 0;
        //  left[0] = nums[0];
        //  right[n-1] = nums[n-1];
        //  for(int i=1;i<n;i++){
        //      left[i] = max(nums[i],left[i-1]);
        //  }
        //  for(int i=n-2;i>=0;i--){
        //      right[i] = max(nums[i],right[i+1]);
        //  }

        // // for(auto it : left) cout<<it<<" ";
        // // cout<<endl;
        // // for(auto it : right) cout<<it<<" ";

        // for(int i=0;i<n;i++){
        //     ans += (min(left[i],right[i]) - nums[i]);
        // }
        // return ans;

        // O(N)
        int n = nums.size(), leftMax = 0, rightMax = 0, l = 0, r = n - 1, ans = 0;
        while (l <= r)
        {
            if (nums[l] <= nums[r])
            {
                if (nums[l] >= leftMax)
                {
                    leftMax = nums[l];
                }
                else
                {
                    ans += (leftMax - nums[l]);
                }
                l++;
            }
            else
            {
                if (nums[r] >= rightMax)
                {
                    rightMax = nums[r];
                }
                else
                {
                    ans += (rightMax - nums[r]);
                }
                r--;
            }
        }
        return ans;
    }
};