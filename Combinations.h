/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Combinations
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/combinations/
 Notes:
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:

 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]

 Solution:   DFS.
 */

#ifndef COMBINATIONS_H_
#define COMBINATIONS_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > all;
        vector<int> combination;
        combine(n, k, 1, combination, all);
        return all;
    }

    void combine(int n, int k, int start, vector<int> &combination, vector<vector<int> > &all) {
        if (!k) {
            all.push_back(combination);
            return;
        }

        for (int i = start; i <= n - k + 1; ++i) {
            combination.push_back(i);
            combine(n, k - 1, i + 1, combination, all);
            combination.pop_back();
        }
    }
};

#endif /* COMBINATIONS_H_ */
