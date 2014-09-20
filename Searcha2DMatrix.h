/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 19, 2014
 Problem:    Search a 2D Matrix
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/search-a-2d-matrix/
 Notes:

 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,

 Consider the following matrix:

 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 Given target = 3, return true.

 Solution:   Binary Search http://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-6
             1. One-pass.
                There is no array of two or more dimensions. A 2D array is really an array whose
                element is an array. All elements are stored row-by-row in consecutive addresses.

             2. Two-pass.
                Binary search the first column to locate a row that might contain target.
                Note that for this step two-branch binary search is essential.

                Binary search the located row for target.
 */

#ifndef SEARCHA2DMATRIX_H_
#define SEARCHA2DMATRIX_H_

#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return searchMatrix2P2B(matrix, target);
    }

    // one-pass & one-branch
    bool searchMatrix1P1B(vector<vector<int> > &A, int target) {
        if (A.empty() || A[0].empty()) return false;

        int m = A.size(), n = A[0].size();
        int low = 0, top = m * n - 1;
        while (low < top) {
            int mid = low + (top - low) / 2;
            int i = mid / n, j = mid % n;
            if (A[i][j] < target) {
                low = mid + 1;
            }
            else {
                top = mid;
            }
        }

        int i = low / n, j = low % n;
        return A[i][j] == target;
    }

    // one-pass & two-branch
    bool searchMatrix1P2B(vector<vector<int> > &A, int target) {
        if (A.empty() || A[0].empty()) return false;

        int m = A.size(), n = A[0].size();
        int low = 0, top = m * n - 1;
        while (low <= top) {
            int mid = low + (top - low) / 2;
            int i = mid / n, j = mid % n;
            if (A[i][j] == target) {
                return true;
            }
            else if (A[i][j] < target) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }

        return false;
    }

    // two-pass & two-branch
    bool searchMatrix2P2B(vector<vector<int> > &A, int target) {
        if (A.empty() || A[0].empty()) return false;
        int m = A.size(), n = A[0].size();

        // binary search the first column
        // two-branch version is necessary here.
        int low = 0, top = m - 1;
        while (low <= top) {
            int mid = low + (top - low) / 2;
            if (A[mid][0] == target) {
                return true;
            }
            else if (A[mid][0] < target) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }
        if (top == -1) return false;

        // search the
        int i = top;    // i-th row to be searched
        low = 1;        // starting from 1 (A[i][0] is already ruled out)
        top = n - 1;
        while (low <= top) {
            int mid = low + (top - low) / 2;
            if (A[i][mid] == target) {
                return true;
            }
            else if (A[i][mid] < target) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }

        return false;
    }
};


#endif /* SEARCHA2DMATRIX_H_ */
