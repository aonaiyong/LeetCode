/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Same Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/same-tree/
 Notes:
 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

 Solution:   DFS & Early Termination.
 */

#ifndef SAMETREE_H_
#define SAMETREE_H_

#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

#endif /* SAMETREE_H_ */
