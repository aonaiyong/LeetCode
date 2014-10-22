/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 22, 2014
 Problem:     Unique Paths
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/unique-paths/
 Notes:
 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 How many possible unique paths are there?

 Solution:    Dynamic Programming.
 */

#ifndef UNIQUEPATHS_H_
#define UNIQUEPATHS_H_

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return uniquePathsLinear(m, n);
    }

    int uniquePathsQuadratic(int m, int n) {
        vector<vector<int> > DP(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                DP[i][j] = DP[i][j-1] + DP[i-1][j];
        }
        return DP[m-1][n-1];
    }

    int uniquePathsLinear(int m, int n) {
        vector<int> DP(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                DP[j] += DP[j-1];
        }
        return DP[n-1];
    }
};

#endif /* UNIQUEPATHS_H_ */
