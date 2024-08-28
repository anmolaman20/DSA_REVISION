//  https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
Longest K unique characters substring
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // O(N)
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[s[r]]++;

            if (mp.size() > k)
            {
                if (--mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }

            if (mp.size() == k)
                maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen == 0 ? -1 : maxLen;
    }
};