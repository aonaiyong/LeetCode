/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Combination Sum
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/combination-sum/
 Notes:
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 The same repeated number may be chosen from C unlimited number of times.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a_1, a_2, … , a_k) must be in non-descending order. (i.e., a_1 ≤ a_2 ≤ … ≤ a_k).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]

 Solution:  Depth-first Search.
 */

#ifndef COMBINATIONSUM_H_
#define COMBINATIONSUM_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> combination;
        combinationSum(candidates, target, 0, combination, result);

        return result;
    }

    void combinationSum(const vector<int> &candidates, int target, int pos,
                        vector<int> &combination, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = pos; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (target < num) break;

            combination.push_back(num);
            combinationSum(candidates, target-num, i, combination, result);
            combination.pop_back();
        }
    }
};

#endif /* COMBINATIONSUM_H_ */
