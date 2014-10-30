/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 30, 2014
 Problem:     Longest Palindromic Substring
 Difficulty:  4
 Source:      https://oj.leetcode.com/problems/longest-palindromic-substring/
 Notes:
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 Solution:
 */

#ifndef LONGESTPALINDROMICSUBSTRING_H_
#define LONGESTPALINDROMICSUBSTRING_H_

#include <string>
using std::string;

#include <utility>
using std::pair; using std::make_pair;

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindromeQuadratic(s);
    }

    string longestPalindromeQuadratic(const string &s) {
        int n = s.size();
        // vector<vector<bool>> DP(n, vector<bool>(n, true));  // Time Limit Exceeded
        bool DP[1000][1000];
        pair<int, int> longest = make_pair(0, 0);
        for (int k = 1; k <= n; ++k) {         // length of substring
            for (int i = 0; i <= n - k; ++i) { // starting index
                int j = i + k - 1;             // ending index
                if (k == 1 || k == 2)
                    DP[i][j] = s[i] == s[j];
                else
                    DP[i][j] = s[i] == s[j] && DP[i+1][j-1];

                if (DP[i][j] && longest.second < k)
                    longest = make_pair(i, k);
            }
        }
        return s.substr(longest.first, longest.second);
    }
};

#endif /* LONGESTPALINDROMICSUBSTRING_H_ */
