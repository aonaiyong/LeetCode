/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 21, 2014
 Problem:     Longest Common Substring
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Longest_common_substring_problem
 Notes:
 Find the longest string (or strings) that is a substring (or are substrings)
 of two or more strings

 Solution:    Dynamic Programming
 */

#ifndef LONGESTCOMMONSUBSTRING_H_
#define LONGESTCOMMONSUBSTRING_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
    int LCSLength(const string &x, const string &y, vector<vector<int> > &DP) {
        int m = x.size(), n = y.size();
        int longest = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                if (x[i-1] == y[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + 1;
                    longest = max(longest, DP[i][j]);
                }
        }

        return longest;
    }
};

#endif /* LONGESTCOMMONSUBSTRING_H_ */
