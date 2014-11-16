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

 Solution:    1. One-pass solution.
                 Calculate the total area and bar area in one pass.

                 Time: O(n), Space: O(1).

              2. Two-pass solution.
                 First, for each bar, calculate the left and right bound.
                 Second, calculate the amount of water that is wrapped above each bar.

                 Time: O(n), Space: O(1).
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
        return trap1P(A, n);
    }

    // One-pass solution
    // Time: O(n), Space: O(1)
    int trap1P(int A[], int n) {
        int totalArea = 0, barArea = 0;
        int minLevel = 0;
        for (int lt = 0, rt = n - 1; lt <= rt; ) {
            // update the total area
            if (min(A[lt], A[rt]) > minLevel) {
                totalArea += (min(A[lt], A[rt]) - minLevel) * (rt - lt + 1);
                minLevel = min(A[lt], A[rt]);
            }
            // update the bar area, and advance the smaller bar
            if (A[lt] < A[rt])
                barArea += A[lt++];
            else
                barArea += A[rt--];
        }
        return totalArea - barArea;
    }

    // Two-pass solution
    // Time: O(n), Space: O(1)
    int trap2P(int A[], int n) {
        vector<int> maxLeft(n, A[0]);
        vector<int> maxRight(n, A[n-1]);
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i-1], A[i]);
            maxRight[n-1-i] = max(maxRight[n-i], A[n-1-i]);
        }

        int area = 0;
        for (int i = 1; i < n - 1; ++i)
            area += min(maxLeft[i], maxRight[i]) - A[i];
        return area;
    }
};

#endif /* TRAPPINGRAINWATER_H_ */
