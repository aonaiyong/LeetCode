/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 19, 2014
 Problem:    Search Insert Position
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/search-insert-position/
 Notes:
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0

 Solution: 1. 2-branch binary search.
              loop invariant:   |    <    |      =?      |    >   |
                                 0         low        top      n-1

              termination:      |    <      |    =    |     >     |
                                 0           low   top         n-1

                                |    <          |       >       |
                                 0           top low         n-1

           2. 1-branch binary search.
              loop invariant:   |    <    |      =?      |   >=   |
                                 0         low        top      n-1
              termination:
 */

#ifndef SEARCHINSERTPOSITION_H_
#define SEARCHINSERTPOSITION_H_

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return searchInsert1B(A, n, target);
    }

    // 2 branches & iterative
    int searchInsert2B(int A[], int n, int target) {
        int low = 0, top = n - 1;
        while (low <= top) {
            int mid = low + (top - low) / 2;
            if (A[mid] == target) {
                return mid;
            }
            else if(A[mid] < target) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }

        return low;
    }

    // 1 branch & iterative
    int searchInsert1B(int A[], int n, int target) {
        if (A[n-1] < target) return n;

        int low = 0, top = n - 1;
        while (low < top) {
            int mid = low + (top - low) / 2;
            if (A[mid] < target) {
                low = mid + 1;
            }
            else {
                top = mid;
            }
        }

        return low;
    }
};

#endif /* SEARCHINSERTPOSITION_H_ */
