// https://leetcode.com/problems/minimum-window-substring/

/*
76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window
substring
of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // O(N^2)
        //  int minLen = 1e9,sind = 0,n = s.size(),cnt=0;
        //  if(t.size()>n) return "";
        //  for(int i=0;i<n;i++){
        //      int hash[256] = {0};
        //      cnt = 0;
        //      for(auto it : t) hash[it]++;
        //      for(int j=i;j<n;j++){
        //          if(hash[s[j]]>0) cnt++;
        //          hash[s[j]]--;
        //          if(cnt==t.size()){
        //              if(j-i+1<minLen){
        //                  minLen = j-i+1;
        //                  sind = i;
        //                  break;
        //              }
        //          }
        //      }
        //  }
        //  return minLen==1e9?"":s.substr(sind,minLen);

        // O(N)

        int hash[256] = {0}, l = 0, r = 0, n = s.size(), m = t.size(), minLen = 1e9, sind = -1, cnt = 0;
        for (int i = 0; i < m; i++)
            hash[t[i]]++;

        while (r < n)
        {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;

            while (cnt == m)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    sind = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        return (sind == -1) ? "" : s.substr(sind, minLen);
    }
};