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
                - For low < high, mid is strictly less than high, which means num[mid] and num[high]
                  are different.
                - If num[mid] > num[high], then the pivot must be in range num[mid+1...high]
                - Otherwise, the pivot must be in range num[low...mid]
 */

#ifndef FINDMINIMUMINROTATEDSORTEDARRAY_H_
#define FINDMINIMUMINROTATEDSORTEDARRAY_H_

#include <vector>
using std::vector;

#include <climits>

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, high = num.size() - 1;
        while (low < high) {                 // initial range num[low...high], where low < high
            int mid = low + (high - low) / 2;// mid >= low and mid < high, so num[mid] != num[high]
            if (num[mid] > num[high])
                low = mid + 1;               // reduced range num[mid+1...high]
            else
                high = mid;                  // reduced range num[low...mid]
        }
        return low == high ? num[low] : INT_MIN;
    }
};

#endif /* FINDMINIMUMINROTATEDSORTEDARRAY_H_ */
