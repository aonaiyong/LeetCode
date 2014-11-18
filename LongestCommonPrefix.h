/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 18, 2014
 Problem:     Longest Common Prefix
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/longest-common-prefix/
 Notes:
 Write a function to find the longest common prefix string amongst an array of strings.

 Solution:    Simply check corresponding positions of each string, and terminate if mismatch is encountered.
 */

#ifndef LONGESTCOMMONPREFIX_H_
#define LONGESTCOMMONPREFIX_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::sort;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        return longestCommonPrefix_2(strs);
    }

    string longestCommonPrefix_1(const vector<string> &strs) {
        if (strs.empty()) return {};
        string prefix;
        int m = strs.size(), n = strs[0].size();
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m ; ++i) {
                if (j >= strs[i].size() || strs[i][j] != strs[0][j])
                    return prefix;
            }

            prefix += strs[0][j];
        }
        return prefix;
    }

    // sort strs in increasing order of string size
    string longestCommonPrefix_2(vector<string> &strs) {
        if (strs.empty()) return {};
        string prefix;
        sort(strs.begin(), strs.end(),
             [](const string &s1, const string &s2) { return s1.size() < s2.size(); } );
        int m = strs.size(), n = strs[0].size();
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m ; ++i) {
                if (strs[i][j] != strs[0][j])
                    return prefix;
            }

            prefix += strs[0][j];
        }
        return prefix;
    }
};

#endif /* LONGESTCOMMONPREFIX_H_ */
