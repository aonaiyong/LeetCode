/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    3 Sum
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

 Solution:   3SUM. http://en.wikipedia.org/wiki/3SUM
 */

#ifndef 3SUM_H_
#define 3SUM_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;

        int n = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2 && num[i] <= 0; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                   vector<int> triplet(3);
                   triplet[0] = num[i];
                   triplet[1] = num[j];
                   triplet[2] = num[k];
                   ret.push_back(triplet);

                   ++j; --k;
                   // skip duplicates
                   while (j < k && num[j] == num[j - 1]) ++j;
                   while (j < k && num[k] == num[k + 1]) --k;
                }
                else if (sum < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }

            // skip duplicates
            while (i < n - 2 && num[i + 1] == num[i]) ++i;
        }

        return ret;
    }
};


#endif /* 3SUM_H_ */
