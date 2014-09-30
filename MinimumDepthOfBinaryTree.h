/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Minimum Depth of Binary Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 Notes:
 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 Solution:   1. Recursive Post-order Traversal.
                Time: O(n), Space: O(n).

             2. Iterative Post-order Traversal.
                Time: O(n), Space: O(n).

             3. Iterative Level-order Traversal.
                Time: O(n), Space: O(n).
                This solution is the most efficient one.
 */

#ifndef MINIMUMDEPTHOFBINARYTREE_H_
#define MINIMUMDEPTHOFBINARYTREE_H_

#include <algorithm>
using std::min;

#include <limits>
using std::numeric_limits;

#include <stack>
using std::stack;

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        return iterativeStackMinDepth(root);
    }

    int recursiveMinDepth(TreeNode *root) {
        if (!root) return 0;
        if (root->left && !root->right) return 1 + recursiveMinDepth(root->left);
        if (!root->left && root->right) return 1 + recursiveMinDepth(root->right);
        int leftDepth = recursiveMinDepth(root->left);
        int rightDepth = recursiveMinDepth(root->right);
        return 1 + min(leftDepth, rightDepth);
    }

    int iterativeStackMinDepth(TreeNode *root) {
        if (!root) return 0;

        int minDepth = numeric_limits<int>::max();
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
                    if (!peakNode->right && !peakNode->left && minDepth > stk.size()) {
                        minDepth = stk.size();
                    }

                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else {
                    root = peakNode->right;
                }
            }
        }

        return minDepth;
    }

    int iterativeQueueMinDepth(TreeNode *root) {
        int minDepth = 0;
        queue<TreeNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            ++minDepth;

            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = frontier.front();
                if (!node->left && !node->right) return minDepth;
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);

                frontier.pop();
            }
        }

        return minDepth;
    }
};

#endif /* MINIMUMDEPTHOFBINARYTREE_H_ */
