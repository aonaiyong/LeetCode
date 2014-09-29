/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Maximum Depth of Binary Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 Notes:
 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 Solution:   Recursion.
             Time: O(n), Space: O(n).
 */

#ifndef MAXIMUMDEPTHOFBINARYTREE_H_
#define MAXIMUMDEPTHOFBINARYTREE_H_

#include <algorithm>
using std::max;

#include "TreeNode.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

#endif /* MAXIMUMDEPTHOFBINARYTREE_H_ */
