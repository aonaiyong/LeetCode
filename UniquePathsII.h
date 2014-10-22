/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 22, 2014
 Problem:     Unique Paths II
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/unique-paths-ii/
 Notes:
 Follow up for "Unique Paths":

 Now consider if some obstacles are added to the grids. How many unique paths would there be?

 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.

 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 The total number of unique paths is 2.

 Note: m and n will be at most 100.

 Solution:    Dynamic Programming.
 */

#ifndef UNIQUEPATHSII_H_
#define UNIQUEPATHSII_H_

#include <vector>
using std::vector;

class Solution {
public:
    // Time: O(m*n), Space: O(m*n)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > DP(m, vector<int>(n));
        for (int i = 0; i < m && !obstacleGrid[i][0]; ++i)
            DP[i][0] = 1;
        for (int j = 0; j < n && !obstacleGrid[0][j]; ++j)
            DP[0][j] = 1;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                DP[i][j] = !obstacleGrid[i][j] ? DP[i][j-1] + DP[i-1][j] : 0;
        }
        return DP[m-1][n-1];
    }
};

#endif /* UNIQUEPATHSII_H_ */
