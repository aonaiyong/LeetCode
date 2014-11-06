/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 4, 2014
 Problem:     Median of Two Sorted Arrays
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
 Notes:
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 The overall run time complexity should be O(log (m+n)).

 Solution:     Meidan. http://en.wikipedia.org/wiki/Median

               1. Count while merging.
                  Time: O(m + n).

               2.

               3. Binary search.
                  Time: O(logm + logn).
 */

#ifndef MEDIANOFTWOSORTEDARRAYS_H_
#define MEDIANOFTWOSORTEDARRAYS_H_

#include <cmath>

#include <algorithm>
using std::min; using std::max;

#include <climits>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0 && n == 0)
            return NAN;
        else
            return findMedianSortedArraysDAC(A, m, B, n);
    }

    // Count while merge. Time: O(m + n).
    double findMedianSortedArraysMerge(int A[], int m, int B[], int n) {
        int prev = 0, curr = 0;
        for (int i = 0, j = 0; i + j <= (m + n) / 2; ) {
            prev = curr;
            // Note: assuming A[m] = B[n] = +INF
            int Ai = i == m ? INT_MAX : A[i];
            int Bj = j == n ? INT_MAX : B[j];
            curr = Ai <= Bj ? A[i++] : B[j++];
        }

        return (m + n) % 2 ? curr : (prev + curr) / 2.0;
    }

    double findMedianSortedArraysDAC(int A[], int m, int B[], int n) {
        int t = m + n;
        if (t % 2)
            return findKthSortedArrays(A, m, B, n, t / 2 + 1);
        else
            return (findKthSortedArrays(A, m, B, n, t / 2) + findKthSortedArrays(A, m, B, n, t / 2 + 1)) / 2;
    }

    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (k == 1)
            return min(A[0], B[0]);

        int i = min(k / 2, m), j = k - i;
        int a = A[i - 1], b = B[j - 1];
        if (a < b)
            return findKthSortedArrays(A + i, m - i, B, j, k - i);
        else if (a > b)
            return findKthSortedArrays(A, i, B + j, n - j, k - j);
        else
            return a;
    }


    // Binary search. Time: O(logm + logn).
    double findMedianSortedArraysBS(int A[], int m, int B[], int n) {
        return medianSearch(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double medianSearch(int A[], int m, int B[], int n, int left, int right) {
         if (right < left)
             return medianSearch(B, n, A, m, max(0, (m + n) / 2 - m), min(n - 1, (m + n) / 2));

         // [left, right] is a subrange of [0, m - 1]
         int i = left + (right - left) / 2;
         int j = (m + n) / 2 - i;

         int Ai_1 = i == 0 ? INT_MIN : A[i - 1];
         int Bj_1 = j == 0 ? INT_MIN : B[j - 1];
         // int Ai = i == m ? INT_MAX : A[i];
         int Ai = A[i];    // i <= m - 1
         int Bj = j == n ? INT_MAX : B[j];

         if (Ai < Bj_1)
             return medianSearch(A, m, B, n, i + 1, right);
         if (Ai > Bj)
             return medianSearch(A, m, B, n, left, i - 1);

         return (m + n) % 2 ? Ai : (Ai + max(Ai_1, Bj_1)) / 2.0;
     }
};

#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */
