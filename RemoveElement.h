/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Element
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/remove-element/
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.

 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution:  Two pointers.
            Loop Invariant:    A   |     !=      |    ==    |      ?     |
                                    0           i            j        n-1

            Initialization:    A   |                  ?                  |
                                  i j                                 n-1

            Termination:       A   |        !=          |      ==        |
                                    0                  i              n-1 j

            Time: O(n), Space: O(1)
 */

#ifndef REMOVEELEMENT_H_
#define REMOVEELEMENT_H_

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = -1;
        for (int j = 0; j < n; ++j) {
            if (A[j] != elem)
                A[++i] = A[j];
        }
        return i + 1;
    }
};

#endif /* REMOVEELEMENT_H_ */
