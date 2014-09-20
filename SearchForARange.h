/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Search for a Range
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/search-for-a-range/
 Notes:

 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Solution:
 */

#ifndef SEARCHFORARANGE_H_
#define SEARCHFORARANGE_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lowerBound(A, n, target);
        int upper = upperBound(A, n, target);
        if (lower == upper || A[lower] != target) {
            return {-1, -1};
        }
        return {lower, upper - 1};
    }

    int lowerBound(int A[], int n, int target) {
        int *B = A;
        while (n > 0) {
            int step = n / 2;
            if (B[step] < target) {
                B += step + 1;
                n -= step + 1;
            }
            else {
                n = step;
            }
        }

        return B - A;
    }

    int upperBound(int A[], int n, int target) {
        int *B = A;
        while (n > 0) {
            int step = n / 2;
            if (B[step] <= target) {
                B += step + 1;
                n -= step + 1;
            }
            else {
                n = step;
            }
        }

        return B - A;
    }
};

#endif /* SEARCHFORARANGE_H_ */
