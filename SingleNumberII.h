/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    Single Number II
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

 Solution:   Count number of 1s.
 */

#ifndef SINGLENUMBERII_H_
#define SINGLENUMBERII_H_

class Solution {
public:
    int singleNumber(int A[], int n) {
        return singleNumberCount(A, n);
    }

    int singleNumberCount(int A[], int n) {
        int single = 0;
        for (int k = 0; k < 32; ++k) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] & 1 << k)
                    ++count;
            }
            if (count % 3)
                single |= 1 << k;
        }
        return single;
    }

    int singleNumberMask(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; ++i) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

#endif /* SINGLENUMBERII_H_ */
