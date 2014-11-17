/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 17, 2014
 Problem:     Largest Rectangle in Histogram
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
 Notes:
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 The largest rectangle is shown in the shaded area, which has area = 10 unit.

 For example,
 Given height = [2,1,5,6,2,3],
 return 10.

 Solution:
 */

#ifndef LARGESTRECTANGLEINHISTOGRAM_H_
#define LARGESTRECTANGLEINHISTOGRAM_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::min; using std::max;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleAreaQuadratic(height);
    }

    // Time: O(n^2), Space: O(1)
    int largestRectangleAreaQuadratic(const vector<int> &height) {
        int maxArea = 0;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && height[i] <= height[i + 1]) // skip non-peak bar
                continue;
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                maxArea = max(maxArea, minHeight * (i - j + 1));
            }
        }
        return maxArea;
    }
};

#endif /* LARGESTRECTANGLEINHISTOGRAM_H_ */
