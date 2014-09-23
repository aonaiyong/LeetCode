/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    Single NumberII.h
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

 Solution:   Count number of 1s.
 */

#ifndef SINGLE_NUMBERII_H_
#define SINGLE_NUMBERII_H_

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;

        for (int i = 0; i < 32; ++i) {
            int count = 0;
            int mask = 1 << i;
            for (int j = 0; j < n; ++j) {
                if (A[j] & mask) ++count;
            }

            if (count % 3) ret |= mask;
        }

        return ret;
    }
};

#endif /* SINGLE_NUMBERII_H_ */
