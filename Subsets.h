/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Sub sets
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/subsets/
 Notes:
 Given a set of distinct integers, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:

 [
   [3],
   [1],
   [2],
   [1,2,3],
   [1,3],
   [2,3],
   [1,2],
   []
 ]

 Solution:   Depth-first Search.
 */

#ifndef SUBSETS_H_
#define SUBSETS_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> power;
        vector<int> sub;

        // for (int k = 0; k <= S.size(); ++k) { // recursive solution 1
        //     subsets(S, k, 0, sub, power);
        // }

        // subsets(S, 0, sub, power); // recursive solution 2

        subsets(S, power);  // iterative solution

        return power;
    }

    // recursive solution 1: for subsets of size k
    void subsets(const vector<int> &S, int k, int pos, vector<int> &sub, vector<vector<int>> &power) {
        if (k == 0) {
            power.push_back(sub);
            return;
        }

        for (int i = pos; i <= S.size() - k; ++i) {
            sub.push_back(S[i]);
            subsets(S, k-1, i+1, sub, power);
            sub.pop_back();
        }
    }

    // recursive solution 2: for all subsets
    void subsets(const vector<int> &S, int pos, vector<int> &sub, vector<vector<int>> &power) {
        power.push_back(sub);
        for (int i = pos; i < S.size(); ++i) {
            sub.push_back(S[i]);
            subsets(S, i+1, sub, power);
            sub.pop_back();
        }
    }

    // iterative solution: merge each element of S into power respectively
    void subsets(const vector<int> &S, vector<vector<int>> &power) {
        power.resize(1); // initially empty
        for (int i = 0; i < S.size(); ++i) {
            int n = power.size();
            for (int j = 0; j < n; ++j) {
                power.push_back(power[j]);
                power.back().push_back(S[i]);
            }
        }
    }
};

#endif /* SUBSETS_H_ */
