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

 Solution:   https://oj.leetcode.com/discuss/857/constant-space-solution
 */

#ifndef SINGLENUMBERII_H_
#define SINGLENUMBERII_H_

#include <algorithm>
using std::max;

#include <cstring>
using std::memset;

class Solution {
public:
    int singleNumber(int A[], int n) {
        // return singleNumberCount(A, n);
        // return singleNumberMask(A, n);
        return singleNumberMask(A, n, 3, 1);
    }

    // Counting
    int singleNumberCount(int A[], int n) {
        int single = 0;
        for (int d = 0; d < 32; ++d) {
            int count = 0;
            int mask = 1 << d;
            for (int i = 0; i < n; ++i) {
                if (A[i] & mask)
                    ++count;
            }
            if (count % 3)
                single |= mask;
        }
        return single;
    }

    // Bit-Manipulation
    int singleNumberMask(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for (int i = 0; i < n; ++i) {
            twos |= ones & A[i];      // mark the bits emerged 2, 3 or more times
            ones ^= A[i];             // mark the bits emerged 1 or 3 times
            xthrees = ~(ones & twos); // exclude the bits emerged 3 or more times
            ones &= xthrees;
            twos &= xthrees;
        }
        return ones;
    }

    // General Solution
    int singleNumberMask(int A[], int n, int k, int l) {
        int m = max(k, l);
        int x[m];
        memset(x, 0, sizeof(x));
        x[0] = ~0;
        for (int i = 0; i < n; ++i) {
            int t = x[m-1];
            for (int j = m - 1; j > 0; --j)
                x[j] = (x[j-1] & A[i]) | (x[j] & ~A[i]);  // carries from previos one + bits not carries to next one
            x[0] = (t & A[i]) | (x[0] & ~A[i]);
        }
        return x[l];
    }
};

#endif /* SINGLENUMBERII_H_ */
