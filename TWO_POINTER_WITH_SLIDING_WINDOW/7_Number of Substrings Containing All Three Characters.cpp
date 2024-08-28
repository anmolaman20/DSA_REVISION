// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

/*
1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        // brute force  TLE
        //  int n = s.size(), ans = 0;
        //  for(int i=0;i<n;i++){
        //      set<char> st;
        //      for(int j=i;j<n;j++){
        //          st.insert(s[j]);
        //          if(st.size()==3){
        //              ans+=(n-j);
        //              break;
        //          }
        //      }
        //  }
        //  return ans;

        // int r = 0,l = 0, n = s.size(),ans =0;
        // unordered_map<int,int>mp;
        // while(r<n){
        //     mp[s[r]]++;
        //     while(mp.size()==3){
        //         ans+=(n-r);
        //         if(--mp[s[l]]==0) mp.erase(s[l]);
        //         l++;
        //     }
        //     r++;
        // }
        // return ans;

        // O(N)
        int a = -1, b = -1, c = -1, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b')
                b = i;
            else
                c = i;

            if (a != -1 and b != -1 and c != -1)
            {
                ans += (1 + min(a, min(b, c)));
            }
        }
        return ans;
    }
};