/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Search for a Range
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/search-for-a-range/
 Notes:

 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

Solution:    One-branch Binary Search (current position and width)
             http://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-6

             1. Lower Bound.
                Index of the first element that's no less than target.

                                               <-----step------>
                Loop invariant:   |     <     |        ?       |     >=      |
                                   A           B

                Termination:      |          <            |          >=       |
                                   A                       B

             2. Upper Bound.
                Index of the first element that's greater than target.

                                               <-----step------>
                Loop invariant:   |     <=    |        ?        |     >      |
                                   A           B

                Termination:      |          <=           |          >       |
                                   A                       B

                If element is not in the array, lower and upper bound would be identical.
                Otherwise, upper bound would be one greater than lower bound.
 */

#ifndef SEARCHFORARANGE_H_
#define SEARCHFORARANGE_H_

#include <vector>
using std::vector;

#include <functional>
using std::less; using std::less_equal;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = Bound(A, n, target, less<int>());
        int upper = Bound(A, n, target, less_equal<int>());
        // int lower = lowerBound(A, n, target);
        // int upper = upperBound(A, n, target);

        if (lower == upper) return {-1, -1};
        return {lower, upper - 1};
    }

    template <typename Compare>
    int Bound(int A[], int n, int target, Compare comp) {
        int *B = A;
        while (n > 0) {        // size n
            int step = n / 2;  // 0 <= step < n
            if (comp(B[step], target)) {
                B += step + 1; // skip B[0], B[1], ..., B[step]
                n -= step + 1; // reduced size n - step - 1
            }
            else {
                n = step;      // reduced size step
            }
        }

        return B - A;
    }

    int lowerBound(int A[], int n, int target) {
        int *B = A;
        while (n > 0) {
            int step = n / 2;
            if (B[step] < target) {
                B += step + 1;
                n -= step + 1;
            }
            else {
                n = step;
            }
        }

        return B - A;
    }

    int upperBound(int A[], int n, int target) {
        int *B = A;
        while (n > 0) {
            int step = n / 2;
            if (B[step] <= target) {
                B += step + 1;
                n -= step + 1;
            }
            else {
                n = step;
            }
        }

        return B - A;
    }
};

#endif /* SEARCHFORARANGE_H_ */
