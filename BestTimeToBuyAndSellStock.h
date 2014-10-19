/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 18, 2014
 Problem:     Best Time to Buy and Sell Stock
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
 Notes:
 Say you have an array for which the i-th element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

 Solution:    Dynamic Programming.
              1. Subproblem = maximum profit of array p[:i] (prefix)
                 - #subprobs = O(|p|)
              2. Guess: one of two possibilities
                 - the maximum profit of p[:i] is the same as that of p[:i-1]
                 - the maximum profit of p[:i] is p[i-1] - min{p[:i]}
              3. Recurrence
                 DP(i) = max(DP(i-1), p[i-1] - p[iMin])
                 - time/subprob = O(1)
              4. for i = 1...|p|
                 - Base case: DP(0) = 0, iMin = 0
              5. Original Problem: DP(|p|)
                 - Time:  #subprobs * time/subprob = O(|p|)
                   Space: only keep the last maximum profit = O(1)
 */

#ifndef BESTTIMETOBUYANDSELLSTOCK_H_
#define BESTTIMETOBUYANDSELLSTOCK_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int iMin = 0, maxP = 0;
        for (int i = 1; i <= prices.size(); ++i) {
            if (prices[i-1] < prices[iMin])
                iMin = i-1;

            maxP = max(maxP, prices[i-1] - prices[iMin]);
        }
        return maxP;
    }
};

#endif /* BESTTIMETOBUYANDSELLSTOCK_H_ */
