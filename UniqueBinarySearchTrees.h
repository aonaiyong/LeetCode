/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 22, 2014
 Problem:     Unique Binary Search Trees
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/unique-binary-search-trees/
 Notes:
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


 Solution:    1. Dynamic Programming.
                 Time: O(n^2), Space: O(n).

              2. Catalan number. http://en.wikipedia.org/wiki/Catalan_number
                 Time: O(n), Space: O(1).
 */

#ifndef UNIQUEBINARYSEARCHTREES_H_
#define UNIQUEBINARYSEARCHTREES_H_

#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        // return numTreesDP(n);
        return catalanNumber(n);
    }

    // Time: O(n^2), Space: O(n)
    int numTreesDP(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j)         // left subtree: j nodes
                dp[i] += dp[j] * dp[i - j - 1]; // right subtree: i - j - 1 nodes
        }
        return dp[n];
    }

    // Time: O(n), Space: O(1)
    int catalanNumber(int n) {
        int cn = 1;
        for (int i = 1; i <= n; ++i)
            cn = cn * (4 * i - 2) / (i + 1);
        return cn;
    }
};

#endif /* UNIQUEBINARYSEARCHTREES_H_ */
