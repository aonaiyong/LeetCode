/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 23, 2014
 Problem:    Plus One
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/plus-one/
 Notes:
 Given a non-negative number represented as an array of digits, plus one to the number.

 The digits are stored such that the most significant digit is at the head of the list.

 Solution:   Math.
 */

#ifndef PLUSONE_H_
#define PLUSONE_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }

        if (carry) 
            digits.insert(digits.begin(), carry);

        return digits;
    }
};

#endif /* PLUSONE_H_ */
