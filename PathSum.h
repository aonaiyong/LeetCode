/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Path Sum
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/path-sum/
 Notes:
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \      \
         7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 Solution:   1. Recursive solution.
                Time: O(n), Space: O(n).

             2. Iterative post-order traversal.
                Time: O(n), Space: O(n).
 */

#ifndef PATHSUM_H_
#define PATHSUM_H_

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return iterativeHasPathSum(root, sum);
    }

    bool recursiveHasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) return sum == 0;
        return recursiveHasPathSum(root->left, sum) ||
               recursiveHasPathSum(root->right, sum);
    }

    bool iterativeHasPathSum(TreeNode *root, int sum) {
        stack<TreeNode *> stk;
        TreeNode *lastNodeVisited = nullptr;
        while (root || !stk.empty()) {
            if (root) {
                sum -= root->val;
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (!peakNode->right || peakNode->right == lastNodeVisited) {
                    if (!peakNode->right && !peakNode->left && !sum)
                        return true;

                    sum += peakNode->val;
                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else
                    root = peakNode->right;
            }
        }
        return false;
    }
};

#endif /* PATHSUM_H_ */
