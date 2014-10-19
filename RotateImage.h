/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    Rotate Image
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/rotate-image/
 Notes:
 You are given an n x n 2D matrix representing an image.

 Rotate the image by 90 degrees (clockwise).

 Follow up:
 Could you do this in-place?

 Solution:
 */

#ifndef ROTATEIMAGE_H_
#define ROTATEIMAGE_H_

#include <vector>
using std::vector;

#include <utility>
using std::swap;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if (!matrix.empty() && !matrix[0].empty())
            rotateOnePass(matrix);
    }

    // n^2/4 4-element swaps
    void rotateOnePass(vector<vector<int>> &A) {
        int n = A.size();
        for (int i = 0; i < n/2; ++i) {
            int last = n-1-i;
            for (int j = i; j < last; ++j) {
                int offset = j - i;

                int top = A[i][j];
                A[i][j] = A[last-offset][i];              // bottom->top
                A[last-offset][i] = A[last][last-offset]; // right->left
                A[last][last-offset] = A[j][last];        // top->bottom
                A[j][last] = top;                         // left->right
            }
        }
    }

    // n^2 2-element swaps
    void rotateTwoPass(vector<vector<int>> &A) {
        int n = A.size();
        // transpose: A[i][j] <-> A[j][i], for j = i+1 to n-1
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j)
                swap(A[i][j], A[j][i]);
        }
        // column j <-> column n-1-j, for j = 0 to n/2 - 1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j)
                swap(A[i][j], A[i][n-1-j]);
        }
    }
};

#endif /* ROTATEIMAGE_H_ */
