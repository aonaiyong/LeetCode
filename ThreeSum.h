/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    3Sum
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/3sum/
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

 Solution:  3SUM. http://en.wikipedia.org/wiki/3SUM
 */

#ifndef THREESUM_H_
#define THREESUM_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;

        sort(num.begin(), num.end());
        int n = num.size();
        for (int i = 0; i < n - 2 && num[i] <= 0; ++i) {
            // skip duplicates
            if (i > 0 && num[i] == num[i-1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                   ret.push_back({num[i], num[j], num[k]});

                   ++j; --k;
                   // skip duplicates
                   while (j < k && num[j] == num[j-1]) ++j;
                   while (j < k && num[k] == num[k+1]) --k;
                }
                else if (sum < 0) ++j;
                else --k;
            }
        }

        return ret;
    }
};


#endif /* THREESUM_H_ */
