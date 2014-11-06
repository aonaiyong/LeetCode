/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 6, 2014
 Problem:     Pow(x, n)
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/powx-n/
 Notes:
 Implement pow(x, n).

 Solution:    1. Recursive solution.
                 Time: O(log|n|), Space: O(log|n|).

              2. Iterative solution.
                 Time: O(log|n|), Space: O(1).
 */

#ifndef POW_X_N__H_
#define POW_X_N__H_

class Solution {
public:
    double pow(double x, int n) {
        return powIter(x, n);
    }

    // Note that for n = INT_MIN, -n is undefined in C++.
    double powRecur(double x, int n) {
        if (n == 0)
            return 1.0;

        double y = pow(x, n / 2), yy = y * y;
        if (n % 2)
            return n > 0 ? x * yy : 1 / x * yy;
        else
            return yy;
    }

    double powIter(double x, int n) {
        double p = 1.0;
        for (int m = n; m; m /= 2, x *= x)
            if (m % 2)
                p *= x;
        return n > 0 ? p : 1 / p;
    }
};

#endif /* POW_X_N__H_ */
