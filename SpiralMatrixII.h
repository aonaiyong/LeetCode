/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Spiral Matrix II
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/spiral-matrix-ii/
 Notes:
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

 For example,
 Given n = 3,

 You should return the following matrix:
 [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
 ]

 Solution:    Process outermost layer at each iteration.
 */

#ifndef SPIRALMATRIXII_H_
#define SPIRALMATRIXII_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > spiral(n, vector<int>(n));
        int imin = 0, imax = n - 1;
        int jmin = 0, jmax = n - 1;
        int num = 0;
        while (true) {  // process outermost layer at each iteration
            // first row
            for (int j = jmin; j <= jmax; ++j) spiral[imin][j] = ++num;
            if (++imin > imax) break;
            // last column
            for (int i = imin; i <= imax; ++i) spiral[i][jmax] = ++num;
            if (--jmax < jmin) break;
            // last row
            for (int j = jmax; j >= jmin; --j) spiral[imax][j] = ++num;
            if (--imax < imin) break;
            // first column
            for (int i = imax; i >= imin; --i) spiral[i][jmin] = ++num;
            if (++jmin > jmax) break;
        }
        return spiral;
    }
};

#endif /* SPIRALMATRIXII_H_ */
