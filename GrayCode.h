/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 4, 2014
 Problem:    Gray Code
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/gray-code/
 Notes:
 The gray code is a binary numeral system where two successive values differ in only one bit.

 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.

 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 Solution:   http://en.wikipedia.org/wiki/Gray_code
             http://www.matrix67.com/blog/archives/266
 */

#ifndef GRAYCODE_H_
#define GRAYCODE_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> grayCode(int n) {
       int N = 1 << n;
       vector<int> sequence(N);
       for (int i = 0; i < N; ++i)
           sequence[i] = i ^ (i >> 1);
       return sequence;
    }
};

#endif /* GRAYCODE_H_ */
