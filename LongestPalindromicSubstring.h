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

#include <algorithm>
using std::min;

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindromeManacher(s);
    }

    // Time: O(n^2), Space: O(n^2)
    string longestPalindromeQuadratic(const string &s) {
        int n = s.size();
        // vector<vector<bool>> DP(n, vector<bool>(n, true));  // Time Limit Exceeded
        bool DP[N][N];
        pair<int, int> longest = make_pair(0, 0);
        for (int k = 1; k <= n; ++k) {         // length of substring
            for (int i = 0; i <= n - k; ++i) { // starting index
                int j = i + k - 1;             // ending index
                if (k == 1 || k == 2)          // two base cases
                    DP[i][j] = s[i] == s[j];
                else
                    DP[i][j] = s[i] == s[j] && DP[i+1][j-1];

                if (DP[i][j] && longest.second < k)
                    longest = make_pair(i, k);
            }
        }
        return s.substr(longest.first, longest.second);
    }

    // Time: O(n^2), Space: O(n)
    string longestPalindromeLinear(const string &s) {
        int n = s.size();
        bool DP[N][2];
        pair<int, int> longest = make_pair(0, 0);
        for (int k = 1; k <= n; ++k) {           // length of substring
            int m = k % 2;                       // parity of k
            for (int i = 0; i <= n - k; ++i) {   // starting index
                int j = i + k - 1;               // ending index;
                if (k == 1 || k == 2)            // two base cases
                    DP[i][m] = s[i] == s[j];
                else
                    DP[i][m] = s[i] == s[j] && DP[i+1][m];

                if (DP[i][m] && longest.second < k)
                    longest = make_pair(i, k);
            }
        }
        return s.substr(longest.first, longest.second);
    }

    // Time: O(n^2), Space: O(1)
    string longestPalindromeConstant(const string &s) {
        int n = s.size();
        pair<int, int> longest = make_pair(0, 0);
        for (int i = 0; i < n; ++i) {      // starting index
            for (int j = 0; j < 2; ++j) {  // two centers
                int lt = i, rt = i + j;    // two boundaries (exclusive)
                while (lt >= 0 && rt <= n-1 && s[lt] == s[rt]) { // expand from center (i, i+j)
                    --lt;
                    ++rt;
                }

                if (longest.second < rt - lt - 1)
                    longest = make_pair(lt + 1, rt - lt - 1);
            }
        }
        return s.substr(longest.first, longest.second);
    }

    // Time: O(n), Space: O(n)
    string longestPalindromeManacher(const string &s) {
        int n = s.size();
        int P[2 * N + 1];
        int id = 0, mx = 0;
        for (int i = 0; i < 2 * n + 1; ++i) {
            int j = 2 * id - i;
            P[i] = mx > i ? min(P[j], mx - i) : 1;
            for (int lt = i - P[i], rt = i + P[i]; lt >= 0 && rt <= 2 * n; --lt, ++rt) {
                if (lt % 2 && s[lt / 2] != s[rt / 2])
                    break;
                else
                    ++P[i];
            }

            if (i + P[i] > mx) {
                id = i;
                mx = i + P[i];
            }
        }

        int centerIndex = 0;
        int maxLen = 0;
        for (int i = 1; i < 2 * n + 1; ++i)
            if (P[i] > P[centerIndex]) {
                centerIndex = i;
                maxLen = P[i] - 1;
            }
        return s.substr((centerIndex - maxLen) / 2, maxLen);
    }

private:
    const int N = 1000;
};

#endif /* LONGESTPALINDROMICSUBSTRING_H_ */
