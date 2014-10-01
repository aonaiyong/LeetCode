/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 30, 2014
 Problem:    Sum Root to Leaf Numbers
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 Notes:
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.

 Find the total sum of all root-to-leaf numbers.

 For example,

     1
    / \
   2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.

 Return the sum = 12 + 13 = 25.

 Solution:   1. Recursive Pre-order Traversal.
                Time: O(n), Space: O(n).

             2. Iterative Level-order Traversal.
                Time: O(n), Space: O(n).
 */

#ifndef SUMROOTTOLEAFNUMBERS_H_
#define SUMROOTTOLEAFNUMBERS_H_

#include <queue>
using std::queue;

#include <utility>
using std::pair; using std::make_pair;

#include "TreeNode.h"

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        iterativeSumNums(root, 0, sum);
        return sum;
    }

    void recursiveSumNums(TreeNode *root, int num, int &sum) {
        if (!root) return;
        num = num * 10 + root->val;
        if (!root->left && !root->right) {
            sum += num;
            return;
        }
        recursiveSumNums(root->left, num, sum);
        recursiveSumNums(root->right, num, sum);
    }

    void iterativeSumNums(TreeNode *root, int num, int &sum) {
        queue<pair<TreeNode *, int>> frontier;
        if (root) frontier.push(make_pair(root, 0));
        while (!frontier.empty()) {
            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                pair<TreeNode *, int> p = frontier.front();
                TreeNode *node = p.first;
                int num = p.second * 10 + node->val;
                if (!node->left && !node->right) sum += num;
                if (node->left) frontier.push(make_pair(node->left, num));
                if (node->right) frontier.push(make_pair(node->right, num));

                frontier.pop();
            }
        }
    }
};

#endif /* SUMROOTTOLEAFNUMBERS_H_ */
