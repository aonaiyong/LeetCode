/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 20, 2014
 Problem:     Shortest Common Supersequence
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Shortest_common_supersequence
 Notes:
 Find the shortest common supersequence of strings x and y, which is a shortest string z
 such that both x and y are subsequences of z

 Solution:    Dynamic Programming.
 */

#ifndef SHORTESTCOMMONSUPERSEQUENCE_H_
#define SHORTESTCOMMONSUPERSEQUENCE_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
public:
    // Time: O(|x|*|y|), Space: O(|x|*|y|)
    int SCSLength(const string &x, const string &y, vector<vector<int> > &DP) {
        int m = x.size(), n = y.size();
        for (int i = 0; i <= m; ++i)
            DP[i][0] = i;
        for (int j = 0; j <= n; ++j)
            DP[0][j] = j;

        for (int i = 1; i <= m; ++i) {
		    for (int j = 1; j <= n; ++j)
		        if (x[i-1] == y[j-1])
			        DP[i][j] = DP[i-1][j-1] + 1;
		        else
		            DP[i][j] = min(DP[i][j-1], DP[i-1][j]) + 1;
        }
        return DP[m][n];
    }

	// Time: O(|x|+|y|), Space: O(|x|*|y|)
	string backtrace(const string &x, const string &y, const vector<vector<int> > &DP, int i, int j) {
		if (i == 0)
			return y.substr(0, j);
		if (j == 0)
			return x.substr(0, i);
		if (x[i-1] == y[j-1])
			return backtrace(x, y, DP, i-1, j-1) + x[i-1];
		if (DP[i][j] == DP[i][j-1] + 1)
			return backtrace(x, y, DP, i, j-1) + y[j-1];
		else
			return backtrace(x, y, DP, i-1, j) + x[i-1];
	}
};


#endif /* SHORTESTCOMMONSUPERSEQUENCE_H_ */
