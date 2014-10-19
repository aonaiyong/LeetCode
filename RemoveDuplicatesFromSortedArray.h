/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2].

 Solution:    Two pointers.
              Property of result array: no duplicates, i.e., consecutive elements are different.

              Loop Invariant:    A   |    unique    |   duplicate    |     ?     |
                                      0            i                j         n-1

              Initialization:    A   | |                   ?                      |
                                      i j                                      n-1

              Termination:       A   |        unique       |      duplicate      |
                                      0                   i                   n-1 j

              Time: O(n), Space: O(1)
 */

#ifndef REMOVEDUPLICATESFROMSORTEDARRAY_H_
#define REMOVEDUPLICATESFROMSORTEDARRAY_H_

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
        	return n;

        int i = 0;
        for (int j = 1; j < n; ++j) {
            if (A[j] != A[i])   // equivalent to A[j] != A[j-1]
                A[++i] = A[j];
        }
        return i + 1;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDARRAY_H_ */
