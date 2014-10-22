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


 Solution:    Dynamic Programming.
 */

#ifndef UNIQUEBINARYSEARCHTREES_H_
#define UNIQUEBINARYSEARCHTREES_H_

#include <vector>
using std::vector;

class Solution {
public:
    int numTrees(int n) {
        vector<int> DP(n + 1, 0);
        DP[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)    // for root j
                DP[i] += DP[j-1] * DP[i-j]; // left subtree: j-1 nodes, right subtree: i-j nodes
        }
        return DP[n];
    }
};

#endif /* UNIQUEBINARYSEARCHTREES_H_ */
