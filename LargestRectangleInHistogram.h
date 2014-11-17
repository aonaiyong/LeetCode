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

 Solution:    1.

              2. For every bar 'x', calculate the area with 'x' as the smallest bar (height)
                 in the rectangle, and find the maximum of all areas.



 */

#ifndef LARGESTRECTANGLEINHISTOGRAM_H_
#define LARGESTRECTANGLEINHISTOGRAM_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::min; using std::max;

#include <stack>
using std::stack;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleAreaLinear(height);
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

    // Time: O(n), Space: O(n)
    int largestRectangleAreaLinear(vector<int> &height) {
        int maxArea = 0;
        stack<int> stk;
        height.push_back(0); //
        int i = 0, n = height.size();
        while (i < n) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i++);
            else {
                int idx = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height[idx] * width);
            }
        }
        return maxArea;
    }

    // if the input vector can not be modified
    // Time: O(n), Space: O(n)
    int largestRectangleAreaLinear2(const vector<int> &height) {
        int maxArea = 0;
        stack<int> stk;
        int i = 0, n = height.size();
        while (i < n) {
            if (stk.empty() || height[i] >= height[stk.top()])
                stk.push(i++);
            else {
                int idx = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height[idx] * width);
            }
        }

        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, height[idx] * width);
        }

        return maxArea;
    }
};

#endif /* LARGESTRECTANGLEINHISTOGRAM_H_ */
