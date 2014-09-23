/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    3SumClosest.h
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/3sum-closest/
 Notes:
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 Solution:   3SUM. http://en.wikipedia.org/wiki/3SUM
 */

#ifndef 3SUMCLOSEST_H_
#define 3SUMCLOSEST_H_

#include <vector>
using std::vector;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = target;

        int n = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) return sum;
                if (sum < target) {
                    ++j;
                }
                else {
                    --k;
                }

                if (ret == target || abs(sum - target) < abs(ret - target)) ret = sum;
            }
        }

        return ret;
    }
};

#endif /* 3SUMCLOSEST_H_ */
