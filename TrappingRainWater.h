/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 16, 2014
 Problem:     Trapping Rain Water
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/trapping-rain-water/
 Notes:
  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 Solution:
 */

#ifndef TRAPPINGRAINWATER_H_
#define TRAPPINGRAINWATER_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::max; using std::min;

class Solution {
public:
    int trap(int A[], int n) {
        vector<int> maxLeft(n, A[0]);
        vector<int> maxRight(n, A[n-1]);
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i-1], A[i]);
            maxRight[n-1-i] = max(maxRight[n-i], A[n-1-i]);
        }

        int result = 0;
        for (int i = 1; i < n - 1; ++i)
            result += min(maxLeft[i], maxRight[i]) - A[i];
        return result;
    }
};

#endif /* TRAPPINGRAINWATER_H_ */
