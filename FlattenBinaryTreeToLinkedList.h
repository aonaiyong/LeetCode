/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 30, 2014
 Problem:    Flatten Binary Tree to Linked List
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 Notes:
 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given

          1
         / \
        2   5
       / \   \
      3   4   6
 The flattened tree should look like:
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

 Solution:   1. Iterative Solution.
                Time: O(n), Space: O(1).

             2. Recursive Solution.
                Time: O(n), Space: O(n).

 */

#ifndef FLATTENBINARYTREETOLINKEDLIST_H_
#define FLATTENBINARYTREETOLINKEDLIST_H_

#include "TreeNode.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        recursiveFlatten(root);
    }

    void iterativeFlatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode *rightMost = root->left;
                while (rightMost->right) {
                    rightMost = rightMost->right;
                }

                rightMost->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            root = root->right;
        }
    }

    void recursiveFlatten(TreeNode *root) {
        if (!root) return;

        if (root->left) {
            TreeNode *rightMost = root->left;
            while (rightMost->right) {
                rightMost = rightMost->right;
            }

            rightMost->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        recursiveFlatten(root->right);
    }
};

#endif /* FLATTENBINARYTREETOLINKEDLIST_H_ */
