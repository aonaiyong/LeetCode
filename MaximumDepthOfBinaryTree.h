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
        return iterativeQueueMaxDepth(root);
    }

    int recursiveMaxDepth(TreeNode *root) {
        if (!root) return 0;
        int leftMax = recursiveMaxDepth(root->left);
        int rightMax = recursiveMaxDepth(root->right);
        return 1 + max(leftMax, rightMax);
    }

    int iterativeStackMaxDepth(TreeNode *root) {
        int maxDepth = 0;
        stack<TreeNode *> stk;
        TreeNode *node = root, *lastNodeVisited = nullptr;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (!peakNode->right || peakNode->right == lastNodeVisited) {
                    if (!peakNode->right && !peakNode->left)
                        maxDepth = max(maxDepth, static_cast<int>(stk.size()));

                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else
                    node = peakNode->right;
            }
        }
        return maxDepth;
    }

    int iterativeQueueMaxDepth(TreeNode *root) {
        int maxDepth = 0;
        queue<TreeNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = frontier.front();
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);
                frontier.pop();
            }
            ++maxDepth;
        }
        return maxDepth;
    }
};

#endif /* MAXIMUMDEPTHOFBINARYTREE_H_ */
