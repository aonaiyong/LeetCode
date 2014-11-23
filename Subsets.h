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

 Solution:   DFS.
 */

#ifndef SUBSETS_H_
#define SUBSETS_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // return subsets_1(S);
        // return subsets_2(S);
        return subsets_3(S);
    }

    // Recursive solution 1: for k = 0...|S|, compute all subsets of size k, respectively
    vector<vector<int> > subsets_1(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power;
        vector<int> sub;
        int n = S.size();
        for (int k = 0; k <= n; ++k)
            subsetsRe_1(S, k, 0, sub, power);
        return power;
    }

    // compute subsets of size k
    void subsetsRe_1(const vector<int> &S, int k, int pos, vector<int> &sub, vector<vector<int> > &power) {
        if (!k) {
            power.push_back(sub);
            return;
        }

        for (int i = pos; i <= S.size() - k; ++i) {
            sub.push_back(S[i]);
            subsetsRe_1(S, k - 1, i + 1, sub, power);
            sub.pop_back();
        }
    }

    // Recursive Solution: for each S[i], i = 0...|S|-1, compute all subsets with S[i] being the first element
    vector<vector<int> > subsets_2(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power;
        vector<int> sub;
        subsetsRe_2(S, 0, sub, power);
        return power;
    }

    void subsetsRe_2(const vector<int> &S, int pos, vector<int> &sub, vector<vector<int> > &power) {
        power.push_back(sub);

        for (int i = pos; i < S.size(); ++i) {
            sub.push_back(S[i]);
            subsetsRe_2(S, i + 1, sub, power);
            sub.pop_back();
        }
    }

    // Iterative Solution: for each S[i], i = 0...|S|-1, expand power, which was initially empty
    vector<vector<int> > subsets_3(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power(1);
        for (int i = 0; i < S.size(); ++i) {
            for (int j = power.size() - 1; j >= 0; --j) {
                power.push_back(power[j]);
                power.back().push_back(S[i]);
            }
        }
        return power;
    }
};

#endif /* SUBSETS_H_ */
