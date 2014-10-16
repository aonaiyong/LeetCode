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

 */

#ifndef FINDMINIMUMINROTATEDSORTEDARRAY_H_
#define FINDMINIMUMINROTATEDSORTEDARRAY_H_

#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, top = num.size() - 1;
        while (low < top) {           // initial range A[low...top], where low < top
            int mid = low + (top - low) / 2;  // mid >= low and mid < top
            if (num[mid] < num[top])
                top = mid;            // reduced range A[low...mid]
            else
                low = mid + 1;        // reduced range A[mid+1...top]
        }

        if (low == top)
            return num[low];
        else
            return -1;
    }
};

#endif /* FINDMINIMUMINROTATEDSORTEDARRAY_H_ */
