/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Search in Rotated SortedArray
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 You are given a target value to search. If found in the array return its index, otherwise return -1.

 You may assume no duplicate exists in the array.

 Solution:    Binary Search http://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-6

              Observation: at least one half of the array is sorted.
 */

#ifndef SEARCHINROTATEDSORTEDARRAY_H_
#define SEARCHINROTATEDSORTEDARRAY_H_

#include <functional>
using std::less;

class Solution {
public:
    int search(int A[], int n, int target) {
        return search2B(A, n, target);
    }

    // Two-branch Binary Search
    int search2B(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target)
            	return mid;               // at this point A[mid] is ruled out
            else if (A[low] <= A[mid]) {  // first half is sorted
                if (A[low] <= target && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else { // second half is sorted
                if (A[mid] < target && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }

    // One-branch Binary Search
    int search1B(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[low] <= A[mid]) {
                if (A[low] <= target && target <= A[mid])
                    return binarySearch(A, low, mid, target, less<int>());
                else
                    low = mid + 1;
            }
            else {  // we have A[low] > A[mid] here, which indicates A[mid] <= A[high]
                if (A[mid] <= target && target <= A[high])
                    return binarySearch(A, mid, high, target, less<int>());
                else
                    high = mid - 1;
            }
        }

        if (low == high && A[low] == target)
            return low;
        else
            return -1;
    }

    template <typename Compare>
    int binarySearch(const int A[], int low, int high, int target, Compare comp) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (comp(A[mid], target))
                low = mid + 1;
            else
                high = mid;
        }

        if (low == high && A[low] == target)
            return low;
        else
            return -1;
     }
};

#endif /* SEARCHINROTATEDSORTEDARRAY_H_ */
