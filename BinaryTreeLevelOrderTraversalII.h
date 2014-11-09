/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    BinaryTreeLevelOrderTraversalII.h
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
 return its bottom-up level order traversal as:
 [
   [15,7],
   [9,20],
   [3]
 ]

 Solution:  http://en.wikipedia.org/wiki/Tree_traversal
            1. Iterative LeverOrder Traversal (BFS & Queue).
               Time: O(n), Space: O(n)

            2. Recursive LeverOrder Traversal (Pre-order & Recursion).
               Time: O(n), Space: O(n)
 */

#ifndef BINARYTREELEVELORDERTRAVERSALII_H_
#define BINARYTREELEVELORDERTRAVERSALII_H_

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > values;
        levelOrder(root, values);
        reverse(values.begin(), values.end());
        return values;
    }

    void levelOrder(TreeNode *root, vector<vector<int> > &values) {
        queue<TreeNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            int n = frontier.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                TreeNode *node = frontier.front();
                level[i] = node->val;
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);

                frontier.pop();
            }
            values.push_back(level);
        }
    }

    void levelOrder(TreeNode *root, int depth, vector<vector<int> > &values) {
        if (!root) return;
        if (values.size() <= depth) values.resize(depth + 1);

        values[depth].push_back(root->val);
        levelOrder(root->left, depth + 1, values);
        levelOrder(root->right, depth + 1, values);
    }
};

#endif /* BINARYTREELEVELORDERTRAVERSALII_H_ */
