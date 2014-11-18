/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Spiral Matrix
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/spiral-matrix/
 Notes:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

 For example,
 Given the following matrix:

 [
  [ 1, 2, 3 ],
  [ 4, 5, 6 ],
  [ 7, 8, 9 ]
 ]

 You should return [1,2,3,6,9,8,7,4,5].

 Solution:    Process outermost layer at each iteration.
 */

#ifndef SPIRALMATRIX_H_
#define SPIRALMATRIX_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiral;
        if (matrix.empty() || matrix[0].empty()) return spiral;
        int m = matrix.size(), n = matrix[0].size();
        int imin = 0, imax = m - 1;
        int jmin = 0, jmax = n - 1;
        while (true) { // process outermost layer at each iteration
            // first row
            for (int j = jmin; j <= jmax; ++j) spiral.push_back(matrix[imin][j]);
            if (++imin > imax) break;
            // last column
            for (int i = imin; i <= imax; ++i) spiral.push_back(matrix[i][jmax]);
            if (--jmax < jmin) break;
            // last row
            for (int j = jmax; j >= jmin; --j) spiral.push_back(matrix[imax][j]);
            if (--imax < imin) break;
            // first column
            for (int i = imax; i >= imin; --i) spiral.push_back(matrix[i][jmin]);
            if (++jmin > jmax) break;
        }
        return spiral;
    }
};

#endif /* SPIRALMATRIX_H_ */
