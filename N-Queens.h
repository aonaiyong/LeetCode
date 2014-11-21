/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 20, 2014
 Problem:     N-Queens
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/n-queens/
 Notes:
 The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

 Given an integer n, return all distinct solutions to the n-queens puzzle.

 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

 For example,
 There exist two distinct solutions to the 4-queens puzzle:

 [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]

 Solution:    Backtracking.
              1. Bit Manipulation. http://www.matrix67.com/blog/archives/266

              2. http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/
 */

#ifndef N_QUEENS_H_
#define N_QUEENS_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstdlib>
using std::abs;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // return solveNQueens_1(n);
        return solveNQueens_2(n);
    }

    // Solution 1: Backtracking + Bit Manipulation (8ms)
    vector<vector<string> > solveNQueens_1(int n) {
        vector<vector<string> > solutions;
        vector<string> sol(n, string(n, '.'));
        solveNQueenRe_2(0, 0, 0, 0, sol, solutions);
        return solutions;
    }

    void solveNQueenRe_2(int i, int row, int ld, int rd, vector<string> &sol, vector<vector<string> > &solutions) {
        int n = sol.size();
        if (row == (1 << n) - 1) {
            solutions.push_back(sol);
            return;
        }

        int candidates = ~(row | ld | rd);
        for (int j = 0; j < n; ++j) {
            int mask = 1 << j;
            if (candidates & mask) {
                sol[i][j] = 'Q';
                solveNQueenRe_2(i + 1, row | mask, (ld | mask) << 1, (rd | mask) >> 1, sol, solutions);
                sol[i][j] = '.';
            }
        }
    }

    // Solution 2: Backtracking (40ms)
    vector<vector<string> > solveNQueens_2(int n) {
        vector<vector<string> > solutions;
        vector<int> col(n, -1);
        solveNQueensRe_2(n, 0, col, solutions);
        return solutions;
    }

    void solveNQueensRe_2(int n, int i, vector<int> &col, vector<vector<string> > &solutions) {
        if (i == n) {
            addBoard(col, solutions);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(col, i, j)) {
                col[i] = j;
                solveNQueensRe_2(n, i + 1, col, solutions);
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

    void addBoard(const vector<int> &col, vector<vector<string> > &solutions) {
        int n = col.size();
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            board[i][col[i]] = 'Q';
        solutions.push_back(board);
    }
};

#endif /* N_QUEENS_H_ */
