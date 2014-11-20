/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Sudoku Solver
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/sudoku-solver/
 Notes:
 Write a program to solve a Sudoku puzzle by filling the empty cells.

 Empty cells are indicated by the character '.'.

 You may assume that there will be only one unique solution.

 Solution:   Backtracking.
             http://www.geeksforgeeks.org/backtracking-set-7-suduku/
 */

#ifndef SUDOKUSOLVER_H_
#define SUDOKUSOLVER_H_

#include <vector>
using std::vector;

class Solution {
private:
    enum { N = 9, n = 3 };
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return;

        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char> > &board, int row, int col) {
        if (!nextUnassigned(board, row, col))
            return true;  // all unassigned cells have been filled, return true

        // get valid candidates for current cell
        vector<bool> candidates(N, true);
        getCandidates(board, row, col, candidates);

        for (int i = 0; i < N; ++i) {
            if (!candidates[i]) continue;

            board[row][col] = '1' + i;
            if (solveSudoku(board, row, col)) return true;
        }
        // all digits have been tried and nothing worked
        // restore the cell and return false
        board[row][col] = '.';
        return false;
    }

    // find row, col of next unassigned cell, return true if such cell is found
    bool nextUnassigned(const vector<vector<char> > &board, int &row, int &col) {
        while (row != N && board[row][col] != '.') {
            col = (col + 1) % N;
            row = col ? row : row + 1;
        }
        return row != N;
    }

    // compute all valid candidates for cell (row, col)
    void getCandidates(const vector<vector<char> > &board, int row, int col, vector<bool> &candidates) {
        int startRow = row/n * n, startCol = col/n * n;
        // iterate over N cells in current row, column, and box respectively
        for (int k = 0; k < N; ++k) {
            if (board[row][k] != '.') candidates[board[row][k] - '1'] = false;
            if (board[k][col] != '.') candidates[board[k][col] - '1'] = false;
            int i = startRow + k/n, j = startCol + k%n;
            if (board[i][j] != '.') candidates[board[i][j] - '1'] = false;
        }
    }
};

#endif /* SUDOKUSOLVER_H_ */
