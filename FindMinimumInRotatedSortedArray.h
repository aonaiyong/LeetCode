/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 16, 2014
 Problem:     Find Minimum in Rotated Sorted Array
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 You may assume no duplicate exists in the array.

 Solution:    Binary Search. http://en.wikipedia.org/wiki/Binary_search_algorithm
              Observation:
                - For low < top, mid is strictly less than top, which means
                  num[mid] and num[top] are not identical.
                - If num[mid] < num[top], then the pivot must be in range num[low...mid]
                - Otherwise, the pivot must be in range num[mid+1...top]
 */

#ifndef FINDMINIMUMINROTATEDSORTEDARRAY_H_
#define FINDMINIMUMINROTATEDSORTEDARRAY_H_

#include <vector>
using std::vector;

#include <limits>
using std::numeric_limits;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, top = num.size() - 1;
        while (low < top) {                 // initial range A[low...top], where low < top
            int mid = low + (top - low) / 2;// mid >= low and mid < top
            if (num[mid] > num[top])
                low = mid + 1;              // reduced range A[mid+1...top]
            else
                top = mid;                  // reduced range A[low...mid]
        }
        return low == top ? num[low] : numeric_limits<int>::min();
    }
};

#endif /* FINDMINIMUMINROTATEDSORTEDARRAY_H_ */
