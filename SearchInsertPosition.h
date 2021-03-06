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
 [1,3,5,6], 5 -> 2
 [1,3,5,6], 2 -> 1
 [1,3,5,6], 7 -> 4
 [1,3,5,6], 0 -> 0

 Solution:    Binary Search http://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-6
              1. One-branch (two index limits).
                 Works even if there're duplicates, in which case the first occurrence is guaranteed to be found.

                 Loop invariant:   |    <    |      =?      |   >=   |
                                    0         low       high      n-1

                 Termination:      |       <       |=?|      >=      |
                                    0              low (high)     n-1
                 Note that low is in range [0,n-1].


              2. Two-Branch (two index limits).
                 Works only when there're no duplicates.

                 Loop invariant:   |    <    |      =?      |    >   |
                                    0         low       high      n-1

                 Termination:      |    <    |      =       |    >   |
                                    0         low       high      n-1

                                   |         <      |        >       |
                                    0           high low          n-1
                 Note that [high,low] could be [-1,0] or [n-1,n].

              3. One-branch (current position and width).
                 See SearchForARange.h for more details.
 */

#ifndef SEARCHINSERTPOSITION_H_
#define SEARCHINSERTPOSITION_H_

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return lowerBound(A, n, target);
    }

    // one-branch (two index limits)
    int searchInsert1B(const int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low < high) {       // search range [low, high], where low < high
            int mid = low + (high - low) / 2;  // mid is in range [low, high)
            if (A[mid] < target)
                low = mid + 1;    // reduced range [mid + 1, high]
            else
                high = mid;        // reduced range [low, mid]
        }
        // At exit of while:
        //    if A[] is empty, then high < low
        //    otherwise high == low

        // deferred test for equality
        if (low == high && A[low] < target)
            return low + 1;
        else
            return low;
    }

    // two-branch (two index limits)
    int searchInsert2B(const int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {      // search range [low, high], where low <= high
            int mid = low + (high - low) / 2;  // mid is in range [low, high]
            if (A[mid] == target)
            	return mid;
            else if(A[mid] < target)
                low = mid + 1;     // reduced range [mid + 1, high]
            else
                high = mid - 1;     // reduced range [low, mid - 1]
        }

        return low;
    }

    // one-branch (current position and width)
    int lowerBound(const int A[], int n, int target) {
        const int *B = A;
        while (n > 0) {         // size n
            int step = n / 2;   // step >= 0 and step < n
            if (B[step] < target) {
                B += step + 1;
                n -= step + 1;  // reduced size n - (step + 1)
            }
            else
                n = step;       // reduced size step
        }

        return B - A;          // note that B might be an off-the-end pointer
    }
};

#endif /* SEARCHINSERTPOSITION_H_ */
