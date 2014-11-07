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

 Solution:
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
        int result = 0;
        int n = height.size();
        for (int i = 0, j = n - 1; i < j; ) {
            if (height[i] < height[j]) {
                result = max(result, height[i] * (j - i));
                ++i;
            }
            else {
                result = max(result, height[j] * (j - i));
                --j;
            }
        }
        return result;
    }
};

#endif /* CONTAINERWITHMOSTWATER_H_ */
