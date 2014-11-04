/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 4, 2014
 Problem:     Find Minimum in Rotated Sorted Array II
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 Notes:
 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 The array may contain duplicates.

 Solution:    Binary Search. http://en.wikipedia.org/wiki/Binary_search_algorithm
              Observation:
              - If num[low] < num[high], then num[low] is the minimum.
              - Otherwise num[low] >= num[high]
                - If num[mid] > num[high], then the pivot must be in num[mid+1...high]
                - If num[mid] < num[low], then the pivot must be in num[low...mid]
                - Otherwise the pivot must be in num[low+1..top]
 */

#ifndef FINDMINIMUMINROTATEDSORTEDARRAYII_H_
#define FINDMINIMUMINROTATEDSORTEDARRAYII_H_

#include <vector>
using std::vector;

#include <limits>
using std::numeric_limits;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, high = num.size() - 1;
        while (low < high && num[low] >= num[high]) { // initial range num[low...high]
            int mid = low + (high - low) / 2;         // mid >= low and mid < high
            if (num[mid] > num[high])     // case 1
                low = mid + 1;            // reduced range num[mid+1...high]
            else if (num[mid] < num[low]) // case 2
                high = mid;               // reduced range num[low...mid]
            else         // case 3
                ++low;   // reduced range num[low+1...high]
        }
        if (num[low] >= num[high])
            return low == high ? num[low] : numeric_limits<int>::min();
        else
            return num[low];
    }
};

#endif /* FINDMINIMUMINROTATEDSORTEDARRAYII_H_ */
