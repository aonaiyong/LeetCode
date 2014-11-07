/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 6, 2014
 Problem:     Divide Two Integers
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/divide-two-integers/
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution:    Let q = div(n, m) and q_i be the i-th bit of q
              then n = (q_31 * 2^31) * m + ... + (q_1 * 2^1) * m + (q_0 * 2^0) * m
              1. top -> down solution. (2 passes)
                 Time: O(logn) (to be exact, 2 * log(n/m) steps).

              2. bottom -> up solution. (log(n/m) passes)
                 Time: O((logn)^2) (to be exact, log(n/m) * (log(n/m) + 1) / 2).
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

        bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long long dividendll = abs(static_cast<long long>(dividend));
        long long divisorll = abs(static_cast<long long>(divisor));
        long long quotient = 0;

         // top -> down
         long long d = divisorll, q = 1;
         while ((d << 1) <= dividendll) {
             d <<= 1;
             q <<= 1;
         }
         while (dividendll >= divisorll) {
             if (dividendll >= d) {
                 dividendll -= d;
                 quotient += q;
             }
             d >>= 1;
             q >>= 1;
         }

//        // bottom -> up
//        while (dividendll >= divisorll) {
//            long long d = divisorll, q = 1;
//            while ((d << 1) <= dividendll) {
//                d <<= 1;
//                q <<= 1;
//            }
//            dividendll -= d;
//            quotient += q;
//        }

        return sign ? -static_cast<int>(quotient) : static_cast<int>(quotient);
    }
};

#endif /* DIVIDETWOINTEGERS_H_ */
