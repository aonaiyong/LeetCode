/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 4, 2014
 Problem:    Subsets II
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/subsets-ii/
 Notes:
 Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:

 [
   [2],
   [1],
   [1,2,2],
   [2,2],
   [1,2],
   []
 ]

 Solution:   Depth-first Search.
 */

#ifndef SUBSETSII_H_
#define SUBSETSII_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> power;
        vector<int> sub;

        // for (int k = 0; k <= S.size(); ++k) { // recursive solution 1
        //     subsetsWithDup(S, k, 0, sub, power);
        // }

        subsetsWithDup(S, 0, sub, power); // recursive solution 2

        // subsetsWithDup(S, power);  // iterative solution

        return power;
    }

    // recursive solution 1: compute subsets of size k
    void subsetsWithDup(const vector<int> &S, int k, int pos, vector<int> &sub, vector<vector<int>> &power) {
        if (k == 0) {
            power.push_back(sub);
            return;
        }

        for (int i = pos; i <= S.size() - k; ++i) {
            if (i > pos && S[i] == S[i-1]) continue;
            sub.push_back(S[i]);
            subsetsWithDup(S, k-1, i+1, sub, power);
            sub.pop_back();
        }
    }

    // recursive solution 2: compute all subsets
    void subsetsWithDup(const vector<int> &S, int pos, vector<int> &sub, vector<vector<int>> &power) {
        power.push_back(sub);
        for (int i = pos; i < S.size(); ++i) {
            if (i > pos && S[i] == S[i-1]) continue;
            sub.push_back(S[i]);
            subsetsWithDup(S, i+1, sub, power);
            sub.pop_back();
        }
    }

    // iterative solution:
    //   for non-duplicates or the first one of consecutive duplicates, expand all;
    //   otherwise, expand only the newly added subsets of the previous iteration.
    void subsetsWithDup(const vector<int> &S, vector<vector<int>> &power) {
        power.resize(1);
        int k; // number of subsets to be expanded
        for (int i = 0; i < S.size(); ++i) {
            int n = power.size();
            if (!i || S[i] != S[i-1]) k = n;

            for (int j = n-1; j >= n-k; --j) {
                power.push_back(power[j]);
                power.back().push_back(S[i]);
            }
        }
    }
};

#endif /* SUBSETSII_H_ */
