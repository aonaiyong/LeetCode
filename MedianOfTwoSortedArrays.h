/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 4, 2014
 Problem:     Median of Two Sorted Arrays
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
 Notes:
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 The overall run time complexity should be O(log (m+n)).

 Solution:    1. Simply count while merging.

 */

#ifndef MEDIANOFTWOSORTEDARRAYS_H_
#define MEDIANOFTWOSORTEDARRAYS_H_

#include <algorithm>
using std::min; using std::max;

#include <climits>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArraysMerge(A, m, B, n);
    }

    double findMedianSortedArraysMerge(int A[], int m, int B[], int n) {
        int prev = 0, curr = 0;
        for (int i = 0, j = 0; i + j <= (m + n) / 2; ) {
            prev = curr;
            int Ai = i == m ? INT_MAX : A[i];
            int Bj = j == n ? INT_MAX : B[j];
            curr = Ai <= Bj ? A[i++] : B[j++];
        }

        return (m + n) % 2 ? curr : (prev + curr) / 2.0;
    }

    double findMedianSortedArraysBS(int A[], int m, int B[], int n) {
        return medianSearch(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double medianSearch(int A[], int m, int B[], int n, int left, int right) {
        if (right < left)
            return medianSearch(B, n, A, m, max(0, (m + n) / 2 - m), min(n - 1, (m + n) / 2));

        int i = (left + right) / 2;
        int j = (m + n) / 2 - i;

        int Ai_1 = i == 0 ? INT_MIN : A[i - 1];
        int Bj_1 = j == 0 ? INT_MIN : B[j - 1];
        int Ai = i == m ? INT_MAX : A[i];
        int Bj = j == n ? INT_MAX : B[j];

        if (Ai < Bj_1)
            return medianSearch(A, m, B, n, i + 1, right);
        if (Ai > Bj)
            return medianSearch(A, m, B, n, left, i - 1);

        return (m + n) % 2 ? Ai : (Ai + max(Ai_1, Bj_1)) / 2.0;
    }

};

#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */
