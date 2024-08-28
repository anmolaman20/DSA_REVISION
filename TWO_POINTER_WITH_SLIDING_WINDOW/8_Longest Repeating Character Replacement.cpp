//  https://leetcode.com/problems/longest-repeating-character-replacement/description/
/*
424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // O(N^2)
        //  int n = s.size(),maxLen = 0, maxFreq=0;
        //  for(int i=0;i<n;i++){
        //      int hash[26] = {0};
        //      for(int j=i;j<n;j++){
        //          hash[s[j]-'A']++;
        //          maxFreq = max(maxFreq,hash[s[j]-'A']);
        //          if(j-i+1-maxFreq<=k){
        //              maxLen = max(maxLen,j-i+1);
        //          }else break;
        //      }
        //  }
        //  return maxLen;

        // //O(N+N) * 26
        // int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        // int n = s.size();
        // int mp[26] = {0};
        // while(r<n){
        //     mp[s[r]-'A']++;
        //     maxFreq = max(maxFreq,mp[s[r]-'A']);
        //     while(r-l+1-maxFreq > k){
        //         mp[s[l]-'A']--;
        //         for(int i=0;i<26;i++) maxFreq = max(maxFreq,mp[i]);
        //         l++;
        //     }
        //     if(r-l+1-maxFreq<=k){
        //         maxLen = max(maxLen,r-l+1);
        //     }
        //     r++;
        // }
        // return maxLen;

        // O(N+N)
        //  int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        //  int n = s.size();
        //  int mp[26] = {0};
        //  while(r<n){
        //      mp[s[r]-'A']++;
        //      maxFreq = max(maxFreq,mp[s[r]-'A']);
        //      while(r-l+1-maxFreq > k){
        //          mp[s[l]-'A']--;
        //          l++;
        //      }
        //      if(r-l+1-maxFreq<=k){
        //          maxLen = max(maxLen,r-l+1);
        //      }
        //      r++;
        //  }
        //  return maxLen;

        // O(N)
        int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        int n = s.size();
        int mp[26] = {0};
        while (r < n)
        {
            mp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mp[s[r] - 'A']);
            if (r - l + 1 - maxFreq > k)
            {
                mp[s[l] - 'A']--;
                l++;
            }
            if (r - l + 1 - maxFreq <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};