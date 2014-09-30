/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Same Tree
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/same-tree/
 Notes:
 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

 Solution:   1. Recursive Pre-order Traversal.
                Time: O(n), Space: O(n).

             2. Iterative with Queue.
                Time: O(n), Space: O(n).
 */

#ifndef SAMETREE_H_
#define SAMETREE_H_

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return iterativeIsSameTree(p, q);
    }

    bool recursiveIsSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return recursiveIsSameTree(p->left, q->left) &&
               recursiveIsSameTree(p->right, q->right);
    }

    bool iterativeIsSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> frontier;
        frontier.push(p);
        frontier.push(q);
        while (!frontier.empty()) {
            p = frontier.front(); frontier.pop();
            q = frontier.front(); frontier.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            frontier.push(p->left); frontier.push(q->left);
            frontier.push(p->right); frontier.push(q->right);
        }

        return true;
    }
};

#endif /* SAMETREE_H_ */
