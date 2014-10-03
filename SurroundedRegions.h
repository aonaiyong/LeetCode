/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Surrounded Regions
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/surrounded-regions/
 Notes:
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region.

 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:

 X X X X
 X X X X
 X X X X
 X O X X

 Solution:   Note that DFS solution can't pass the longest test case, which exhausts the
             call stack and results in stack overflow runtime error.
 */

#ifndef SURROUNDEDREGIONS_H_
#define SURROUNDEDREGIONS_H_

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include <utility>
using std::pair; using std::make_pair;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
       if (board.empty() || board[0].empty()) return;

       int M = board.size(), N = board[0].size();
       for (int i = 0; i < M; ++i) {
           for (int j = 0; j < N; ++j) {
               if (i == 0 || i == M-1 || j == 0 || j == N-1)
                   bfs(board, i, j);
           }
       }

       for (int i = 0; i < M; ++i) {
           for (int j = 0; j < N; ++j) {
               if (board[i][j] == 'B') board[i][j] = 'O';
               else board[i][j] = 'X';
           }
       }
    }

    // can't pass the longest test case, which exhausts the
    // call stack and result in stack overflow runtime error
    void dfs(vector<vector<char>> &board, int row, int col) {
        int M = board.size(), N = board[0].size();
        if (row < 0 || row > M-1 || col < 0 || col > N-1) return;
        if (board[row][col] != 'O') return;

        board[row][col] = 'B';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }

    void bfs(vector<vector<char>> &board, int row, int col) {
        int M = board.size(), N = board[0].size();
        queue<pair<int, int>> frontier;
        if (board[row][col] == 'O') frontier.push(make_pair(row, col));
        while (!frontier.empty()) {
            row = frontier.front().first;
            col = frontier.front().second;
            frontier.pop();

            if (board[row][col] != 'O') continue;
            board[row][col] = 'B';
            if (row > 0) frontier.push(make_pair(row-1, col));
            if (row < M-1) frontier.push(make_pair(row+1, col));
            if (col > 0) frontier.push(make_pair(row, col-1));
            if (col < N-1) frontier.push(make_pair(row, col+1));
        }
    }
};

#endif /* SURROUNDEDREGIONS_H_ */
