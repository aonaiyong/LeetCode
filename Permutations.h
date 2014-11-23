/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 23, 2014
 Problem:     Permutations
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/permutations/
 Notes:
  Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution:    DFS.
 */

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <vector>
using std::vector<bool>;

#include <utility>
using std::swap;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        return permute_1(num);
        // return permute_2(num);
    }

    // Recursive Solution 1: swap in place
    vector<vector<int> > permute_1(vector<int> &num) {
        vector<vector<int> > all;
        permuteRe_1(num, 0, all);
        return all;
    }

    void permuteRe_1(vector<int> &num, int k, vector<vector<int> > &all) {
        int n = num.size();
        if (k == n) {
            all.push_back(num);
            return;
        }

        for (int i = k; i < n; ++i) {
            swap(num[k], num[i]);
            permuteRe_1(num, k + 1, all);
            swap(num[k], num[i]);
        }
    }

    // Recursive Solution 2: use an auxiliary array to keep track of elements that have been used
    vector<vector<int> > permute_2(const vector<int> &num) {
        vector<vector<int> > all;
        vector<int> permutation;
        vector<bool> candidates(num.size(), true);
        permuteRe_2(num, candidates, permutation, all);
        return all;
    }

    void permuteRe_2(const vector<int> &num, vector<bool> &candidates, vector<int> &permutation, vector<vector<int> > &all) {
        int n = num.size(), k = permutation.size();
        if (k == n) {
            all.push_back(permutation);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (candidates[i]) {
                candidates[i] = false;
                permutation.push_back(num[i]);
                permuteRe_2(num, candidates, permutation, all);
                permutation.pop_back();
                candidates[i] = true;
            }
        }
    }
};

#endif /* PERMUTATIONS_H_ */
