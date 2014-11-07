/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    4Sum
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/4sum/
 Notes:
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a 鈮�b 鈮�c 鈮�d)
 The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

 Solution:   3SUM. http://en.wikipedia.org/wiki/3SUM
 */

#ifndef FOURSUM_H_
#define FOURSUM_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
       vector<vector<int>> result;

       sort(num.begin(), num.end());
       int n = num.size();
       for(int i = 0; i < n - 3; ++i) {
           // skip duplicates
           if (i > 0 && num[i] == num[i - 1])
               continue;

           for (int j = i + 1; j < n - 2; ++j) {
               // skip duplicates
               if (j > i + 1 && num[j] == num[j-1])
                   continue;

               int k = j + 1, l = n - 1;
               while (k < l) {
                   int sum = num[i] + num[j] + num[k] + num[l];
                   if (sum == target) {
                       result.push_back({num[i], num[j], num[k], num[l]});

                       ++k; --l;
                       // skip duplicates
                       while (k < l && num[k] == num[k-1]) ++k;
                       while (k < l && num[l] == num[l+1]) --l;
                   }
                   else if (sum < target)
                       ++k;
                   else
                       --l;
               }
           }
       }

       return result;
    }
};

#endif /* FOURSUM_H_ */
