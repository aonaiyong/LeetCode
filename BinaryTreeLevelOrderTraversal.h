/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Binary Tree LevelOrder Traversal
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
 return its level order traversal as:
 [
   [3],
   [9,20],
   [15,7]
 ]
 Solution:  http://en.wikipedia.org/wiki/Tree_traversal
            1. Iterative LeverOrder Traversal (Queue).
               Time: O(n), Space: O(n)

            2. Recursive LeverOrder Traversal.
               Time: O(n), Space: O(n)
 */

#ifndef BINARYTREELEVELORDERTRAVERSAL_H_
#define BINARYTREELEVELORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> vals;
        // iterativeLevelOrder(root, vals);
        recursiveLevelOrder(root, 0, vals);
        return vals;
    }

    void iterativeLevelOrder(TreeNode *root, vector<vector<int>> &vals) {
        queue<TreeNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            // process together all nodes in current frontier (level)
            int n = frontier.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                // the front node is discovered
                TreeNode *node = frontier.front();
                level[i] = node->val;
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);

                // the front node is finished
                frontier.pop();
            }
            vals.push_back(level);
        }
    }

    void recursiveLevelOrder(TreeNode *root, int depth, vector<vector<int>> &vals) {
        if (!root) return;
        if (vals.size() <= depth) vals.resize(depth + 1);

        vals[depth].push_back(root->val);
        recursiveLevelOrder(root->left, depth+1, vals);
        recursiveLevelOrder(root->right, depth+1, vals);
    }
};

#endif /* BINARYTREELEVELORDERTRAVERSAL_H_ */
