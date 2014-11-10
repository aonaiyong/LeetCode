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

 Solution:   1. Recursive Solution.
                Time: O(n), Space: O(n).

             2. Iterative with Queue.
                Time: O(n), Space: O(n).
 */

#ifndef SYMMETRICTREE_H_
#define SYMMETRICTREE_H_

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return iterativeIsSymmetric(root->left, root->right);
    }

    bool recursiveIsSymmetric(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return recursiveIsSymmetric(p->left, q->right) &&
               recursiveIsSymmetric(p->right, q->left);
    }

    bool iterativeIsSymmetric(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> frontier;
        frontier.push(p); frontier.push(q);
        while (!frontier.empty()) {
            p = frontier.front(); frontier.pop();
            q = frontier.front(); frontier.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            frontier.push(p->left); frontier.push(q->right);
            frontier.push(p->right); frontier.push(q->left);
        }
        return true;
    }
};

#endif /* SYMMETRICTREE_H_ */
