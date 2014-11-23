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
        return subsetsWithDup_3(S);
    }

    // Recursive solution 1: for k = 0...|S|, compute all subsets of size k, respectively
    vector<vector<int> > subsetsWithDup_1(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power;
        vector<int> sub;
        for (int k = 0; k <= S.size(); ++k)
            subsetsWithDupRe_1(S, k, 0, sub, power);
        return power;
    }

     // compute subsets of size k
    void subsetsWithDupRe_1(const vector<int> &S, int k, int pos, vector<int> &sub, vector<vector<int> > &power) {
        if (!k) {
            power.push_back(sub);
            return;
        }

        for (int i = pos; i <= S.size() - k; ++i) {
            if (i > pos && S[i] == S[i-1]) continue;  // skip duplicates

            sub.push_back(S[i]);
            subsetsWithDupRe_1(S, k - 1, i + 1, sub, power);
            sub.pop_back();
        }
    }

    // Recursive Solution: for each S[i], i = 0...|S|-1, compute all subsets with S[i] being the first element
    vector<vector<int> > subsetsWithDup_2(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power;
        vector<int> sub;
        subsetsWithDupRe_2(S, 0, sub, power);
        return power;
    }

    void subsetsWithDupRe_2(const vector<int> &S, int pos, vector<int> &sub, vector<vector<int> > &power) {
        power.push_back(sub);

        for (int i = pos; i < S.size(); ++i) {
            if (i > pos && S[i] == S[i-1]) continue;

            sub.push_back(S[i]);
            subsetsWithDupRe_2(S, i + 1, sub, power);
            sub.pop_back();
        }
    }

    // iterative solution:
    //   for non-duplicates or the first one of consecutive duplicates, expand all;
    //   otherwise, expand only the newly added subsets of the previous iteration.
    vector<vector<int> > subsetsWithDup_3(vector<int> &S) {
        sort(S.begin(), S.end());

        vector<vector<int> > power(1);
        int k = 0;
        for (int i = 0; i < S.size(); ++i) {
            int n = power.size();
            if (!i || S[i] != S[i-1])
                k = n;
            for (int j = n - 1; j >= n - k; --j) {
                power.push_back(power[j]);
                power.back().push_back(S[i]);
            }
        }
        return power;
    }
};

#endif /* SUBSETSII_H_ */
