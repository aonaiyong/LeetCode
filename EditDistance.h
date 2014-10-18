/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 18, 2014
 Problem:     Edit Distance
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/edit-distance/
 Notes:
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character

 Solution:    Dynamic Programming.
              1. Subproblem = edit distance on x[:i] & y[:j] (prefixes)
                 - #subprobs = O(|x|*|y|)
              2. Guess: one of 3 possibilities
                 - replace x[i-1]->y[j-1]
                 - insert y[j-1]
                 - delete x[i-1]
              3. Recurrence
                 DP(i, j) =  DP(i-1, j-1),   if x[i-1] == y[j-1]
                             min(min(DP(i-1, j-1), DP(i, j-1)), DP(i-1, j)) + 1,  otherwise
                 - time/subprob = O(1)
              4. for i = 1...|x|
                     for j = 1...|y|
                 - row-by-row (as shown above)
                 - column-by-column
                 - anti-diagonal

                 Base case: DP(0, j) = j, DP(i, 0) = i

              5. Original Problem: DP(|x|, |y|)
                 - Shortest path from (0, 0) to (|x|, |y|) in the DAG (visualized as a
                   2-dimensional matrix). Each cell in the matrix corresponds to a node
                   in the DAG.
                 - Time: #subprobs * time/subprob = O(|x|*|y|)
                   Space: only keep the last row (column) = O(|y|) (O(|x|))
 */

#ifndef EDITDISTANCE_H_
#define EDITDISTANCE_H_
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistanceQuadratic(word1, word2);
    }

    // Time: O(M * N), Space: O(M * N)
    int minDistanceQuadratic(const string &word1, const string &word2) {
        int M = word1.size(), N = word2.size();
        vector<vector<int>> DP(M + 1, vector<int>(N + 1));
        for (int i = 1; i <= M; ++i)
            DP[i][0] = i;
        for (int j = 1; j <= N; ++j)
            DP[0][j] = j;

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (word1[i-1] == word2[j-1])
                    DP[i][j] = DP[i-1][j-1];
                else
                    DP[i][j] = min(min(DP[i-1][j-1], DP[i][j-1]), DP[i-1][j]) + 1;
            }
        }
        return DP[M][N];
    }

    // Time: O(M * N), Space: O(N)
    int minDistanceLinear(const string &word1, const string &word2) {
        int M = word1.size(), N = word2.size();
        vector<int> DP(N + 1);
        for (int j = 1; j <= N; ++j)
            DP[j] = j;

        for (int i = 1; i <= M; ++i) {
            int prev = i;
            for (int j = 1; j <= N; ++j) {
                int curr;
                if (word1[i-1] == word2[j-1])
                    curr = DP[j-1];
                else
                    curr = min(min(DP[j-1], prev), DP[j]) + 1;

                DP[j-1] = prev;
                prev = curr;
            }
            DP[N] = prev;
        }
        return DP[N];
    }
};

#endif /* EDITDISTANCE_H_ */
