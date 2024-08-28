//  https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest
substring
 without repeating characters.
*/

/*
Summary
Approach 1 (Set):

Time Complexity: O(n log n) in the worst case.
Space Complexity: O(n).
Approach 2 (Hash Array):

Time Complexity: O(n).
Space Complexity: O(1).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // int l = 0, r = 0, max_len = 0;
        // set<char> st;
        // while(r<s.size()){
        //     while(st.count(s[r])){
        //         st.erase(s[l++]);
        //     }
        //     st.insert(s[r]);
        //     max_len = max(max_len,r-l+1);
        //     r++;
        // }
        // return max_len;

        int hash[256];
        for (int i = 0; i < 256; i++)
            hash[i] = -1;
        int l = 0, r = 0, maxLen = 0;
        while (r < s.size())
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            maxLen = max(maxLen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
