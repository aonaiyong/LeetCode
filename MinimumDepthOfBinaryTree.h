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

#include <climits>

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
        if (!root->left) return 1 + recursiveMinDepth(root->right);
        if (!root->right) return 1 + recursiveMinDepth(root->left);

        int leftMin = recursiveMinDepth(root->left);
        int rightMin = recursiveMinDepth(root->right);
        return 1 + min(leftMin, rightMin);
    }

    int iterativeStackMinDepth(TreeNode *root) {
        if (!root) return 0;

        int minDepth = INT_MAX;
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
                        minDepth = min(minDepth, static_cast<int>(stk.size()));
                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else
                    node = peakNode->right;
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
