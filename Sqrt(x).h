/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Sqrt(x)
 Difficulty: 4
 Source:     https://github.com/leetcoders/LeetCode
 Notes:
 Implement int sqrt(int x).

 Compute and return the square root of x.

 Solution:   1. Newton's method. http://en.wikipedia.org/wiki/Newton%27s_method
                y = f(t) = t^2 - x;

             2. Binary search in range [0, x].
 */

#ifndef SQRT_X__H_
#define SQRT_X__H_

class Solution {
public:
    int sqrt(int x) {
        return sqrtNewtonsMethod(x);
    }

    // Rate of convergence is quadratic, which means the
    // number of correct bits roughly doubles in every step
    int sqrtNewtonsMethod(int x) {
        if (x == 0) return 0;

        double prev = 0, curr = 1;
        while (curr != prev) {
            prev = curr;
            curr = (curr + x / curr) / 2;
        }

        return static_cast<int>(curr);
    }

    // only works for integer square root
    int sqrtBinarySearch(int x) {
        long long low = 0;
        long long top = x;
        while (low <= top) {
            long long mid = low + (top - low) / 2;
            long long square = mid * mid;
            if (square == x) {
                return mid;
            }
            else if (square < x) {
                low = mid + 1;
            }
            else {
                top = mid - 1;
            }
        }

        return static_cast<int>(top);
    }
};

#endif /* SQRT_X__H_ */
