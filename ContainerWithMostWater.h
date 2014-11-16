/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 7, 2014
 Problem:     Container With Most Water
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/container-with-most-water/
 Notes:
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container.

 Solution:    Two pointers.
              Time: O(n), Space: O(1).

              A   |                              |
                   i                            j
              S[i, j] = min(A[i], A[j]) * (j - i)
              I.  If A[i] < A[j], then S[i, j] = A[i] * (j - i).
                  For all k < j, we have S[i, k] = min(A[i], A[k]) * (k - i)
                                                 < A[i] * (j - i) = S[i, j].
              II. If A[i] >= A[j], similarly we have S[k, j] < S[i, j] for all k > i.
 */

#ifndef CONTAINERWITHMOSTWATER_H_
#define CONTAINERWITHMOSTWATER_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            if (height[i] < height[j]) {
                area = max(area, height[i] * (j-i));
                ++i;
            }
            else {
                area = max(area, height[j] * (j-i));
                --j;
            }
        }
        return area;
    }
};

#endif /* CONTAINERWITHMOSTWATER_H_ */
