/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 4, 2014
 Problem:     Median of Two Sorted Arrays
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
 Notes:
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 The overall run time complexity should be O(log (m+n)).

 Solution:
 */

#ifndef MEDIANOFTWOSORTEDARRAYS_H_
#define MEDIANOFTWOSORTEDARRAYS_H_

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArraysMerge(A, m, B, n);
    }

    double findMedianSortedArraysMerge(int A[], int m, int B[], int n) {
        int k = m + n;
        int prev = 0, curr = 0;
        for (int i = 0, j = 0; i + j <= k / 2; ) {
            prev = curr;
            if (i == m)
                curr = B[j++];
            else if (j == n)
                curr = A[i++];
            else
                curr = A[i] <= B[j] ? A[i++] : B[j++];
        }

        if (k & 0x1)
            return curr;
        else
            return (prev + curr) / 2.0;
    }
};

#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */
