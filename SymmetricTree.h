/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    SymmetricTree.h
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/symmetric-tree/
 Notes:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree is symmetric:

     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
     1
    / \
   2   2
    \   \
    3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

 Solution:
 */

#ifndef SYMMETRICTREE_H_
#define SYMMETRICTREE_H_

#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetricRecur(root->left, root->right);
    }

    bool isSymmetricRecur(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return isSymmetricRecur(root1->left, root2->right) &&
               isSymmetricRecur(root1->right, root2->left);
    }
};

#endif /* SYMMETRICTREE_H_ */
