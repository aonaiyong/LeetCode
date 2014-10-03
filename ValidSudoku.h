/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 2, 2014
 Problem:    Valid Sudoku
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/valid-sudoku/
 Notes:
 Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

 Solution:
 */

#ifndef VALIDSUDOKU_H_
#define VALIDSUDOKU_H_

#include <vector>
using std::vector;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int n = 9;
        int row = 0, col[n] = {0}, box[n] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;

                int mask = 1 << (board[i][j] - '1');
                int k = i/3 * 3 + j/3;
                if ((row & mask) || (col[j] & mask) || (box[k] & mask)) return false;
                row |= mask;
                col[j] |= mask;
                box[k] |= mask;
            }
            row = 0;
        }

        return true;
    }
};

#endif /* VALIDSUDOKU_H_ */
