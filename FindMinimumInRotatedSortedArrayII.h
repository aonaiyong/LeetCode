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
                - If num[mid] > num[top], then the pivot must be in range num[mid+1...top]
                - If num[mid] < num[left], then the pivot must be in range num[low...top]
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
        int low = 0, top = num.size() - 1;
        while (low < top && num[low] >= num[top]) {
            int mid = low + (top - low) / 2;
            if (num[mid] > num[top])
                low = mid + 1;
            else if (num[mid] < num[low])
                top = mid;
            else
                ++low;
        }
        if (num[low] >= num[top])
            return low == top ? num[low] : numeric_limits<int>::min();
        else
            return num[low];
    }
};

#endif /* FINDMINIMUMINROTATEDSORTEDARRAYII_H_ */
