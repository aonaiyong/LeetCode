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

             Loop Invariant:    A   |               |        |       ?      |
                                     0         i-1 i          j          n-1

             Initialization:    A   |     |                ?                |
                                     i-1 i j                             n-1

             Termination:       A   |                       |               |
                                     0                 i-1 i             n-1 j

             Time: O(n), Space: O(1)
 */

#ifndef REMOVEDUPLICATESFROMSORTEDARRAYII_H_
#define REMOVEDUPLICATESFROMSORTEDARRAYII_H_

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
        	return n;

        int i = 1;
        for (int j = 2; j < n; ++j) {
            if (A[j] != A[i] || A[j] != A[i-1])
                A[++i] = A[j];
        }
        return i + 1;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDARRAYII_H_ */
