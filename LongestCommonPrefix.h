/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Longest Common Prefix
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/longest-common-prefix/
 Notes:
 Write a function to find the longest common prefix string amongst an array of strings.

 Solution:    Simply compare corresponding positions of each string, and terminate if a mismatch is encountered.
 */

#ifndef LONGESTCOMMONPREFIX_H_
#define LONGESTCOMMONPREFIX_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::min;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        return longestCommonPrefix_2(strs);
    }

    string longestCommonPrefix_1(const vector<string> &strs) {
        if (strs.empty()) return {};
        int m = strs.size(), n = strs[0].size();
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i)
                if (j >= strs[i].size() || strs[i][j] != strs[0][j])
                    return strs[0].substr(0, j);
        }
        return strs[0];
    }

    string longestCommonPrefix_2(const vector<string> &strs) {
        if (strs.empty()) return {};
        size_t m = strs.size(), n = strs[0].size();
        // Compute the minimum string size first
        for (int i = 1; i < m; ++i)
            n = min(n, strs[i].size());

        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i)
                if (strs[i][j] != strs[0][j])
                    return strs[0].substr(0, j);
        }
        return strs[0].substr(0, n);
    }
};

#endif /* LONGESTCOMMONPREFIX_H_ */
