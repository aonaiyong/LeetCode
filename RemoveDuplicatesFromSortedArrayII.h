/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Duplicates from Sorted ArrayII
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array A = [1,1,1,2,2,3],

 Your function should return length = 5, and A is now [1,1,2,2,3].

 Solution:   Two pointers.
             Property of result array: at most two consecutive duplicates.
 */

#ifndef REMOVEDUPLICATESFROMSORTEDARRAYII_H_
#define REMOVEDUPLICATESFROMSORTEDARRAYII_H_

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;

        int i = 1;
        for (int j = 2; j < n; ++j) {
            if (A[j] != A[i] || A[j] != A[i-1]) {
                A[++i] = A[j];
            }
        }

        return i + 1;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDARRAYII_H_ */
