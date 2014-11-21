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

        // solveSudoku_1(board);
        solveSudoku_2(board);
    }

    // Solution 1: Backtracking + Bit manipulation (8ms)
    void solveSudoku_1(vector<vector<char> > &board) {
        int row[N] = {0}, col[N] = {0}, box[N] = {0};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == '.') continue;

                int mask = 1 << board[i][j] - '1';
                int k = i/n * n + j/n;
                // set bit
                row[i] |= mask;
                col[j] |= mask;
                box[k] |= mask;
            }
        }
        solveSudokuRe_1(board, row, col, box, 0, 0);
    }

    bool solveSudokuRe_1(vector<vector<char> > &board, int row[], int col[], int box[], int i, int j) {
        if (!nextUnassigned(board, i, j))
            return true;  // all unassigned cells have been filled, return true

        int k = i/n * n + j/n;
        int candidates = ~(row[i] | col[j] | box[k]);

        for (int d = 0; d < N; ++d) {
            int mask = 1 << d;
            if (candidates & mask) {
                board[i][j] = '1' + d;
                // set bit
                row[i] |= mask;
                col[j] |= mask;
                box[k] |= mask;
                if (solveSudokuRe_1(board, row, col, box, i, j)) return true;
                // clear bit
                row[i] &= ~mask;
                col[j] &= ~mask;
                box[k] &= ~mask;
            }
        }
        // all digits have been tried and nothing worked
        // restore the cell and return false
        board[i][j] = '.';
        return false;
    }

    // Solution 2: Backtracking + Iteration (240ms)
    void solveSudoku_2(vector<vector<char> > &board) {
        solveSudokuRe_2(board, 0, 0);
    }

    bool solveSudokuRe_2(vector<vector<char> > &board, int i, int j) {
        if (!nextUnassigned(board, i, j))
            return true;  // all unassigned cells have been filled, return true

        // get valid candidates for current cell
        vector<bool> candidates(N, true);
        getCandidates(board, i, j, candidates);

        for (int d = 0; d < N; ++d) {
            if (!candidates[d]) continue;

            board[i][j] = '1' + d;
            if (solveSudokuRe_2(board, i, j)) return true;
       }
        // all digits have been tried and nothing worked
        // restore the cell and return false
        board[i][j] = '.';
        return false;
    }

    // find next unassigned cell, return true if such cell is found
    bool nextUnassigned(const vector<vector<char> > &board, int &i, int &j) {
        while (i != N && board[i][j] != '.') {
            j = (j + 1) % N;
            i = j ? i : i + 1;
        }
        return i != N;
    }

    // compute all valid candidates for cell (i, i)
    void getCandidates(const vector<vector<char> > &board, int i, int j, vector<bool> &candidates) {
        int boxStartRow = i/n * n, boxStartCol = j/n * n;
        // iterate over N cells in current row, column, and box respectively
        for (int k = 0; k < N; ++k) {
            if (board[i][k] != '.') candidates[board[i][k] - '1'] = false;
            if (board[k][j] != '.') candidates[board[k][j] - '1'] = false;
            int bi = boxStartRow + k/n, bj = boxStartCol + k%n;
            if (board[bi][bj] != '.') candidates[board[bi][bj] - '1'] = false;
        }
    }
};


#endif /* SUDOKUSOLVER_H_ */
