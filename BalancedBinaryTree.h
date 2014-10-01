/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Balanced Binary Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/balanced-binary-tree/
 Notes:
 Given a binary tree, determine if it is height-balanced.

 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 Solution:   Recursive Post-order Traversal.
             Time: O(n), Space: O(n).
 */

#ifndef BALANCEDBINARYTREE_H_
#define BALANCEDBINARYTREE_H_

#include <cstdlib>
using std::abs;

#include <algorithm>
using std::max;

#include "TreeNode.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalanced(root, height);
    }

    bool isBalanced(TreeNode *root, int &height) {
        if (!root) return true;

        int leftHeight = 0, rightHeight = 0;
        if (!isBalanced(root->left, leftHeight)) return false;
        if (!isBalanced(root->right, rightHeight)) return false;
        if (abs(leftHeight - rightHeight) > 1) return false;

        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};

#endif /* BALANCEDBINARYTREE_H_ */
