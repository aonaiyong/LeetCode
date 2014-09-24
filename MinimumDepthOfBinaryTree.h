/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Minimum Depth of Binary Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 Notes:
 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 Solution:  DFS.
 */

#ifndef MINIMUMDEPTHOFBINARYTREE_H_
#define MINIMUMDEPTHOFBINARYTREE_H_

#include <algorithm>
using std::min;

#include "TreeNode.h"

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

#endif /* MINIMUMDEPTHOFBINARYTREE_H_ */
