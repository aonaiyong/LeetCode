/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 21, 2014
 Problem:     Maximum Subarray
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/maximum-subarray/
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.

 Solution:    Dynamic Programming.
              1. Subproblem = maximum subarray ending at i (suffix A[h...i] of prefix A[0...i])
                 #subprobs = O(n)
              2. Guess: one of 2 possibilities
                 - extend maximum subarray ending at i-1
                 - start a new maximum subarray containing only A[i]
              3. Recurrence
                 DP(i) =  A[0],                       if i == 0
                          max(DP(i-1) + A[i], A[i]),  if i > 0
                 - time/subprob = O(1)
              4. for i = 1...n-1
              5. max{DP[0], ..., DP[n-1]}
 */

#ifndef MAXIMUMSUBARRAY_H_
#define MAXIMUMSUBARRAY_H_

#include <algorithm>
using std::max;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int largest = A[0], DP = A[0];
        for (int i = 1; i < n; ++i) {
            DP = max(DP + A[i], A[i]);
            largest = max(largest, DP);
        }
        return largest;
    }
};

#endif /* MAXIMUMSUBARRAY_H_ */
