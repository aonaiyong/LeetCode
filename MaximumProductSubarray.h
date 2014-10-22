/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 22, 2014
 Problem:     Maximum Product Subarray
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/maximum-product-subarray/
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.

 Solution:    Dynamic Programming.
 */

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::min; using std::max;

#include <utility>
using std::swap;

class Solution {
public:
    int maxProduct(int A[], int n) {
        return maxProductConstant(A, n);
    }

    int maxProductLinear(int A[], int n) {
        vector<int> minDP(n), maxDP(n);
        minDP[0] = maxDP[0] = A[0];
        int largest = A[0];
        for (int i = 1; i < n; ++i) {
            minDP[i] = minDP[i-1];
            maxDP[i] = maxDP[i-1];
            if (A[i] < 0)
                swap(minDP[i], maxDP[i]);
            minDP[i] = min(minDP[i] * A[i], A[i]);
            maxDP[i] = max(maxDP[i] * A[i], A[i]);
            largest = max(largest, maxDP[i]);
        }
        return largest;
    }

    int maxProductConstant(int A[], int n) {
        int minDP = A[0], maxDP = A[0];
        int largest = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] < 0)
                swap(minDP, maxDP);
            minDP = min(minDP * A[i], A[i]);
            maxDP = max(maxDP * A[i], A[i]);
            largest = max(largest, maxDP);
        }
        return largest;
    }
};


#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */
