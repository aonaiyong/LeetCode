/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 19, 2014
 Problem:     Maximal Rectangle
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/maximal-rectangle/
 Notes:
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 Solution:    1. Dynamic Programming.
                 Time: O(m * n^2), Space: O(m * n).

              2. Dynamic Programming.
                 Time: O(m * n^2), Space: O(n).

              3. For each row, compute the "largest rectangle area in histogram".
                 Time: O(m * n), Space: O(n).

 */

#ifndef MAXIMALRECTANGLE_H_
#define MAXIMALRECTANGLE_H_

#include <vector>
using std::vector;

#include <utility>
using std::pair; using std::make_pair;

#include <algorithm>
using std::min; using std::max;

#include <stack>
using std::stack;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        return maximalRectangleLRIH(matrix);
    }

    // Dynamic Programming
    // Time: O(m * n^2), Space: O(m * n)
    int maximalRectangleDP_1(const vector<vector<char> > &matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        pair<int, int> dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;

                int length = j ? dp[i][j-1].first + 1 : 1;
                int height = i ? dp[i-1][j].second + 1 : 1;
                dp[i][j] = make_pair(length, height);
                for (int k = j; k > j - length; --k) {
                    height = min(height, dp[i][k].second);
                    maxArea = max(maxArea, (j - k + 1) * height);
                }
            }
        }
        return maxArea;
    }

    // Dynamic Programming
    // Time: O(m * n^2), Space: O(n)
    int maximalRectangleDP_2(const vector<vector<char> > &matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    dp[j] = 0;
                    continue;
                }

                dp[j] = i ? dp[j] + 1 : 1;
                int height = dp[j];
                for (int k = j; k >= 0 && matrix[i][k] == '1'; --k) {
                    height = min(height, dp[k]);
                    maxArea = max(maxArea, (j - k + 1) * height);
                }
            }
        }
        return maxArea;
    }

    // For each row, compute the "largest rectangle area in histogram"
    // Time: O(m * n), Space: O(n)
    int maximalRectangleLRIH(const vector<vector<char> > &matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1, 0); // append a bar of length zero
        for (int i = 0; i < m; ++i) {
            // build the histogram (Dynamic Programming)
            for (int j = 0; j < n; ++j)
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }

    int largestRectangleArea(const vector<int> &height) {
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
        return maxArea;
    }
};

#endif /* MAXIMALRECTANGLE_H_ */
