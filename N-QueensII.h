/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 21, 2014
 Problem:     N-Queens II
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/n-queens-ii/
 Notes:
 Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of distinct solutions.

 Solution:    Backtracking.
              1. Bit Manipulation.
                 http://www.matrix67.com/blog/archives/266

              2. http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
 */

#ifndef N_QUEENSII_H_
#define N_QUEENSII_H_

#include <vector>
using std::vector;

class Solution {
public:
    int totalNQueens(int n) {
        // return totalNQueens_1(n);
        return totalNQueens_2(n);
    }

    // Solution 1: Backtracking + Bit Manipulation (4ms)
    int totalNQueens_1(int n) {
        int total = 0;
        totalNQueensRe_1((1 << n) - 1, 0, 0, 0, total);
        return total;
    }

    void totalNQueensRe_1(int upperlim, int row, int ld, int rd, int &total) {
        if (row == upperlim) {
            ++total;
            return;
        }

        int candidates = upperlim & ~(row | ld | rd);
        while (candidates) {
            int p = candidates & -candidates;   // rightmost 1 (-candidates is equivalent to ~candidates + 1)
            candidates -= p;
            totalNQueensRe_1(upperlim, row | p, (ld | p) << 1, (rd | p) >> 1, total);
        }
    }

    // Solution 2: Backtracking (12ms)
    int totalNQueens_2(int n) {
        int total = 0;
        vector<int> col(n);
        totalNQueensRe_2(0, col, total);
        return total;
    }

    void totalNQueensRe_2(int i, vector<int> &col, int &total) {
        int n = col.size();
        if (i == n) {
            ++total;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(col, i, j)) {
                col[i] = j;
                totalNQueensRe_2(i + 1, col, total);
            }
        }
    }

    bool isSafe(const vector<int> &col, int i, int j) {
        for (int k = 0; k < i; ++k) {
            if (j == col[k] || abs(j - col[k]) == i - k)
                return false;
        }
        return true;
    }
};

#endif /* N_QUEENSII_H_ */
