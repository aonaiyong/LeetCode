/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 3, 2014
 Problem:    Palindrome Partitioning
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/palindrome-partitioning/
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return all possible palindrome partitioning of s.

 For example, given s = "aab",
 Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

 Solution:  Depth-first Search.
 */

#ifndef PALINDROMEPARTITIONING_H_
#define PALINDROMEPARTITIONING_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> part;
        partition(s, 0, part, result);
        return result;
    }

    void partition(const string &s, int start, vector<string> &part, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(part);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            string sub = s.substr(start, i - start + 1);
            if (!isPalindrome(sub)) continue;
            part.push_back(sub);
            partition(s, i + 1, part, result);
            part.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        for (int i = 0, j = s.size()-1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

#endif /* PALINDROMEPARTITIONING_H_ */
