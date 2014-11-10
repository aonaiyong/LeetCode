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
        int ht = 0;
        return isBalanced(root, ht);
    }

    bool isBalanced(TreeNode *root, int &ht) {
        if (!root) return true;

        int lht = 0, rht = 0;
        if (!isBalanced(root->left, lht)) return false;
        if (!isBalanced(root->right, rht)) return false;
        ht = 1 + max(lht, rht);
        return abs(lht - rht) <= 1;
    }
};

#endif /* BALANCEDBINARYTREE_H_ */
