/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 20, 2014
 Problem:     Longest Common Subsequence
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Longest_common_subsequence_problem
 Notes:
 Find the longest subsequence common to two sequences. (Note that a subsequence is different from
 a substring, for the terms of the former need not be consecutive terms of the original sequence.)

 Solution:    Dynamic Programming.
 */

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

class Solution {
public:
	// Time: O(|x|*|y|), Space: O(|x|*|y|)
	int LCSLength(const string &x, const string &y, vector<vector<int> > &DP) {
		int m = x.size(), n = y.size();
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j)
				if (x[i-1] == y[j-1])
					DP[i][j] = DP[i-1][j-1] + 1;
				else
					DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
		}
		return DP[m][n];
	}

	// Time: O(|x|+|y|), Space: O(|x|*|y|)
	string backtrace(const string &x, const string &y, const vector<vector<int> > &DP, int i, int j) {
		if (i == 0 || j == 0)
			return "";
		if (x[i-1] == y[j-1])
			return backtrace(x, y, DP, i-1, j-1) + x[i-1];
		if (DP[i][j] == DP[i][j-1])
			return backtrace(x, y, DP, i, j-1);
		else
			return backtrace(x, y, DP, i-1, j);
	}
};

#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */
