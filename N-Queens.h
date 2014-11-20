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
        vector<vector<string> > solutions;
        vector<int> column(n, -1);
        solveNQueens(column, 0, solutions);
        return solutions;
    }

    void solveNQueens(vector<int> &column, int row, vector<vector<string> > &solutions) {
        int n = column.size();
        if (row == n) {
            addBoard(column, solutions);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(column, row, j)) {
                column[row] = j;
                solveNQueens(column, row + 1, solutions);
                column[row] = -1;
            }
        }
    }

    bool isSafe(const vector<int> &column, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == column[i] || abs(col - column[i]) == row - i)
                return false;
        }
        return true;
    }

    void addBoard(vector<int> &column, vector<vector<string> > &solutions) {
        int n = column.size();
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i)
            board[i][column[i]] = 'Q';
        solutions.push_back(board);
    }
};

#endif /* N_QUEENS_H_ */
