/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 22, 2014
 Problem:     Combination Sum II
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/combination-sum-ii/
 Notes:
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

 Each number in C may only be used once in the combination.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]

 Solution:    DFS.
 */

#ifndef COMBINATIONSUMII_H_
#define COMBINATIONSUMII_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        vector<vector<int> > all;
        vector<int> combination;
        combinationSum2(num, target, 0, combination, all);
        return all;
    }

    void combinationSum2(const vector<int> &num, int target, int pos,
                         vector<int> &combination, vector<vector<int> > &all) {
        if (!target) {
            all.push_back(combination);
            return;
        }

        for (int i = pos; i < num.size() && num[i] <= target; ++i) {
            if (i > pos && num[i] == num[i-1]) continue;  // skip duplicates
            combination.push_back(num[i]);
            combinationSum2(num, target - num[i], i + 1, combination, all);
            combination.pop_back();
        }
    }
};

#endif /* COMBINATIONSUMII_H_ */
