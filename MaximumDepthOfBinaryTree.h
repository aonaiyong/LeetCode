/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Maximum Depth of Binary Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 Notes:
 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 Solution:   1. Recursive Post-order Traversal.
                Time: O(n), Space: O(n).

             2. Iterative Post-order Traversal.
                Time: O(n), Space: O(n).

             3. Iterative Level-order Traversal.
                Time: O(n), Space: O(n).
 */

#ifndef MAXIMUMDEPTHOFBINARYTREE_H_
#define MAXIMUMDEPTHOFBINARYTREE_H_

#include <algorithm>
using std::max;

#include <stack>
using std::stack;

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        return iterativeStackMaxDepth(root);
    }

    int recursiveMaxDepth(TreeNode *root) {
        if (!root) return 0;
        int leftDepth = recursiveMaxDepth(root->left);
        int rightDepth = recursiveMaxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int iterativeStackMaxDepth(TreeNode *root) {
        int maxDepth = 0;
        stack<TreeNode *> stk;
        TreeNode *lastNodeVisited = nullptr;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (!peakNode->right || peakNode->right == lastNodeVisited) {
                    if (!peakNode->right && !peakNode->left && maxDepth < stk.size()) {
                        maxDepth = stk.size();
                    }

                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else {
                    root = peakNode->right;
                }
            }
        }

        return maxDepth;
    }

    int iterativeQueueMaxDepth(TreeNode *root) {
        int maxDepth = 0;
        queue<TreeNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            ++maxDepth;

            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = frontier.front();
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);

                frontier.pop();
            }
        }

        return maxDepth;
    }
};

#endif /* MAXIMUMDEPTHOFBINARYTREE_H_ */
