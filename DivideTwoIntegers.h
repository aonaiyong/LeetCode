/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 6, 2014
 Problem:     Divide Two Integers
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/divide-two-integers/
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution:
 */

#ifndef DIVIDETWOINTEGERS_H_
#define DIVIDETWOINTEGERS_H_

#include <cassert>

#include <cstdlib>
using std::abs;

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);

        bool negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long long dividendll = abs(static_cast<long long>(dividend));
        long long divisorll = abs(static_cast<long long>(divisor));
        long long quotient = 0;
        while (dividendll >= divisorll) {
            long long d =  divisorll, q = 1;
            while ((d << 1) <= dividendll) {
                d <<= 1;
                q <<= 1;
            }
            dividendll -= d;
            quotient += q;
        }

        return negative ? -quotient : quotient;
    }
};

#endif /* DIVIDETWOINTEGERS_H_ */
