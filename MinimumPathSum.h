/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 11, 2014
 Problem:     Minimum Path Sum
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/minimum-path-sum/
 Notes:
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.

 Solution:    Dynamic Programming.
 */

#ifndef MINIMUMPATHSUM_H_
#define MINIMUMPATHSUM_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
       return minPathSumLinear(grid);
    }

    // Time: O(m * n), Space: O(min(m, n)
    int minPathSumLinear(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; ++j)
            dp[j] = dp[j-1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
        return dp[n-1];
    }

    // Time: O(m * n), Space: O(m * n)
    int minPathSumQuadratic(vector<vector<int> > &grid) {
       int m = grid.size(), n = grid[0].size();
       vector<vector<int> > dp(m, vector<int>(n));
       dp[0][0] = grid[0][0];
       for (int i = 1; i < m; ++i)
           dp[i][0] = dp[i-1][0] + grid[i][0];
       for (int j = 1; j < n; ++j)
           dp[0][j] = dp[0][j-1] + grid[0][j];
       for (int i = 1; i < m; ++i) {
           for (int j = 1; j < n; ++j)
               dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
       }
       return dp[m-1][n-1];
    }
};

#endif /* MINIMUMPATHSUM_H_ */
