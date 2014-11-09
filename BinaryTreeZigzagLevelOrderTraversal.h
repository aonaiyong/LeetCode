/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    BinaryTreeZigzagLevelOrderTraversal.h
 Difficulty:
 Source:
 Notes:
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
 return its zigzag level order traversal as:
 [
   [3],
   [20,9],
   [15,7]
 ]

 Solution:   Iterative with Queue.
             Time: O(n), Space: O(n).
 */

#ifndef BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_
#define BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > values;
        queue<TreeNode *> frontier;
        bool leftToRight = true;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            int n = frontier.size();
            vector<int> level(n);
            for (int i = 0; i < n; ++i) {
                TreeNode *node = frontier.front();
                int j = leftToRight ? i : n - 1 - i;
                level[j] = node->val;
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);
                frontier.pop();
            }
            values.push_back(level);
            leftToRight = !leftToRight;
        }
        return values;
    }
};

#endif /* BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_ */
