/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 3, 2014
 Problem:     Add Binary
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/add-binary/
 Notes:
 Given two binary strings, return their sum (also a binary string).

 For example,
 a = "11"
 b = "1"
 Return "100".

 Solution:    Math.
 */

#ifndef ADDBINARY_H_
#define ADDBINARY_H_

#include <string>
using std::string;

#include <algorithm>
using std::max;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size(), k = max(m, n);
        string c(k, ' ');
        int carry = 0;
        while (m || n) {
            int sum = carry;
            if (m)
                sum += a[--m] - '0';
            if (n)
                sum += b[--n] - '0';

            carry = sum / 2;
            c[--k] = sum % 2 + '0';
        }
        if (carry)
            c.insert(c.begin(), '1');
        return c;
    }
};

#endif /* ADDBINARY_H_ */
