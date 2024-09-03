// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
/*
1945. Sum of Digits of String After Convert
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int help(string ans,int k){
    //     while(ans.size()>1 and k){
    //         int sum = 0;
    //         for(char c:ans){
    //             sum += (c-'0');
    //         }
    //         // cout<<sum<<endl;
    //         ans = to_string(sum);
    //         k--;
    //     }
    //     return stoi(ans);
    // }
    string rec(int k, string s)
    {
        if (k <= 0)
        {
            return s;
        }
        int sum = 0;
        for (char c : s)
        {
            sum += (c - '0');
        }
        s = to_string(sum);
        cout << s << endl;
        return rec(k - 1, s);
    }
    int getLucky(string s, int k)
    {
        string ans;
        for (char c : s)
        {
            ans += to_string(c - 'a' + 1);
        }
        cout << ans << endl;
        return stoi(rec(k, ans));
    }
};