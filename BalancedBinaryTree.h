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
        // return isBalancedTwo(root, ht);
        return isBalancedOne(root) != -1;
    }

    bool isBalancedTwo(TreeNode *root, int &ht) {
        if (!root) return true;

        int lht = 0, rht = 0;
        if (!isBalancedTwo(root->left, lht)) return false;
        if (!isBalancedTwo(root->right, rht)) return false;
        ht = 1 + max(lht, rht);
        return abs(lht - rht) <= 1;
    }

    int isBalancedOne(TreeNode *root) {
        if (!root) return 0;

        int lht = 0, rht = 0;
        if ((lht = isBalancedOne(root->left)) == -1) return -1;
        if ((rht = isBalancedOne(root->right)) == -1) return -1;
        if (abs(lht - rht) > 1) return -1;
        return 1 + max(lht, rht);
    }
};

#endif /* BALANCEDBINARYTREE_H_ */
