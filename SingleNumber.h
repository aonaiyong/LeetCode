/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    Single Number
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/single-number/
 Notes:
 Given an array of integers, every element appears twice except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

 Solution:   x^y^y = x^0 = x.
 */

#ifndef SINGLENUMBER_H_
#define SINGLENUMBER_H_

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret ^= A[i];
        }

        return ret;
    }
};

#endif /* SINGLENUMBER_H_ */
