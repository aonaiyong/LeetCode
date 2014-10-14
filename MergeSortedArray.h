/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Merge Sorted Array
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/merge-sorted-array/
 Notes:
 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
 The number of elements initialized in A and B are m and n respectively.

 Solution:   Copy from back to forth.
 */

#ifndef MERGESORTEDARRAY_H_
#define MERGESORTEDARRAY_H_

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0)
            A[k--] = A[i] <= B[j] ? B[j--] : A[i--];

        while (j >= 0)
            A[k--] = B[j--];
    }
};

#endif /* MERGESORTEDARRAY_H_ */
