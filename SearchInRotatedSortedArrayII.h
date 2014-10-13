/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Search In Rotated Sorted Array II
 Difficulty: 5
 Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
 Notes:
 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?

 Write a function to determine if a given target is in the array.

 Solution:   Linear search http://en.wikipedia.org/wiki/Linear_search
             See the following link for more details.
             https://oj.leetcode.com/discuss/223/when-there-are-duplicates-the-worst-case-is-could-we-do-better
 */

#ifndef SEARCHINROTATEDSORTEDARRAYII_H_
#define SEARCHINROTATEDSORTEDARRAYII_H_

class Solution {
public:
    bool search(int A[], int n, int target) {
        return linearSearch(A, n, target);
    }

    bool linearSearch(int A[], int n, int target) {
        for (int i = 0; i < n; ++i)
            if (A[i] == target)
            	return true;
        return false;
    }
};

#endif /* SEARCHINROTATEDSORTEDARRAYII_H_ */
