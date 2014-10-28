/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 21, 2014
 Problem:     Longest Common Substring
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Longest_common_substring_problem
 Notes:
 Find the longest string (or strings) that is a substring (or are substrings)
 of two or more strings

 Solution:    Dynamic Programming.
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
    int LCSSubstr(const string &x, const string &y, vector<int> &end) {
        int m = x.size(), n = y.size();
        vector<int> DP(n+1);
        int longest = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j)
                if (x[i-1] == y[j-1]) {
                    DP[j] = DP[j-1] + 1;
                    if (DP[j] >= longest) {
                        if (DP[j] > longest)
                            end.clear();
                        end.push_back(i-1);
                        longest = DP[j];
                    }
                }
        }

        return longest;
    }
};

#endif /* LONGESTCOMMONSUBSTRING_H_ */
