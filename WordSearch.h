/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 1, 2014
 Problem:    Word Search
 Difficulty:
 Source:
 Notes:
 Given a 2D board and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

 For example,
 Given board =

 [
   ["ABCE"],
   ["SFCS"],
   ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 Solution:  Depth-first Search.
            Adj[(i,j)] = {(i-1,j), (i+1,j), (i,j-1), (i,j+1)}.
 */

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int m = board.size(), n = board[0].size();
        vector<vector<char>> color(m, vector<char>(n, 'w')); // 'w': white (undiscovered), 'g': gray (discovered)
                                                             // 'b': black (finished)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, color, i, j, 0, word)) return true;
            }
        }
        return false;
    }

    bool exist(const vector<vector<char>> &board, vector<vector<char>> &color,
               int i, int j, int depth, const string &word) {
        int m = board.size(), n = board[0].size();
        if (depth == word.size()) return true;
        if (i < 0 || i > m-1 || j < 0 || j > n-1) return false;

        if (color[i][j] != 'w') return false;
        if (board[i][j] != word[depth]) return false;
        color[i][j] = 'g';

        if (exist(board, color, i-1, j, depth+1, word)) return true;
        if (exist(board, color, i+1, j, depth+1, word)) return true;
        if (exist(board, color, i, j-1, depth+1, word)) return true;
        if (exist(board, color, i, j+1, depth+1, word)) return true;
        color[i][j] = 'w';
        return false;
    }
};

#endif /* WORDSEARCH_H_ */
