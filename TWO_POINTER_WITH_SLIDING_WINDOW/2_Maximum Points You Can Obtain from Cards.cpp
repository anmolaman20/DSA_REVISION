//  https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

/*
1423. Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {

        // One way of Doing that
        //  vector<int> temp;
        //  int n = (int) cardPoints.size();
        //  for(int i=n-k;i<n;i++){
        //      temp.push_back(cardPoints[i]);
        //  }
        //  for(int i=0;i<k;i++){
        //      temp.push_back(cardPoints[i]);
        //  }

        // for(auto it : temp)  cout<<it<<" ";

        // //applying sliding window
        // int sum = 0;
        // for(int i=0;i<k;i++) sum += temp[i];
        // int l = 0,r=k-1;
        // int max_sum = sum;
        // int ts = temp.size();
        // while(r<ts-1){
        //     sum = sum - temp[l++] + temp[++r];
        //     max_sum = max(max_sum,sum);
        // }
        // return max_sum;

        // Optimized way
        int n = cardPoints.size();
        int l = 0, r1 = k - 1, r2 = n - 1, ls = 0, rs = 0, sum = 0;
        for (int i = 0; i < k; i++)
            sum += cardPoints[i];
        int maxSum = sum;
        while (r1 >= 0)
        {
            sum = sum - cardPoints[r1--];
            sum = sum + cardPoints[r2--];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};