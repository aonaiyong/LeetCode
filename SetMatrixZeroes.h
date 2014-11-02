/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 2, 2014
 Problem:     Set Matrix Zeroes
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/set-matrix-zeroes/
 Notes:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?

 Solution:    1. Use two auxiliary arrays to flag whether there's 0 in a given row/column.
                 Time: O(mn), Space: O(m + n).
              2. Use the first row/column to flag whether there's 0 in a given row/column of the rest of the matrix.
                 Time: O(mn), Space: O(1).
 */

#ifndef SETMATRIXZEROES_H_
#define SETMATRIXZEROES_H_

#include <vector>
using std::vector;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        setZeroesConstant(matrix);
    }

    // Time: O(mn), Space: O(m + n)
    void setZeroesLinear(vector<vector<int> > &A) {
        int m = A.size(), n = A[0].size();
        vector<bool> row(m, false), col(n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (!A[i][j])
                    row[i] = col[j] = true;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                if (row[i] || col[j])
                    A[i][j] = 0;
        }
    }

    // Time: O(mn), Space: O(1)
    void setZeroesConstant(vector<vector<int> > &A) {
        int m = A.size(), n = A[0].size();

        // check whether there is 0 in the first row/column
        bool setFirstRowZero = false, setFirstColZero = false;
        for (int j = 0; j < n && !setFirstRowZero; ++j)
            setFirstRowZero = !A[0][j];
        for (int i = 0; i < m && !setFirstColZero; ++i)
            setFirstColZero = !A[i][0];

        // use the first row/col as flags
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                if (!A[i][j])
                    A[i][0] = A[0][j] = 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                if (!A[i][0] || !A[0][j])
                    A[i][j] = 0;
        }

        // set the first row/column to 0, if necessary
        if (setFirstRowZero) {
            for (int j = 0; j < n; ++j)
                A[0][j] = 0;
        }
        if (setFirstColZero) {
            for (int i = 0; i < m; ++i)
                A[i][0] = 0;
        }
    }
};

#endif /* SETMATRIXZEROES_H_ */
