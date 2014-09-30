/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 30, 2014
 Problem:    Validate Binary Search Tree
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/validate-binary-search-tree/
 Notes:
 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 Solution:
 */

#ifndef VALIDATEBINARYSEARCHTREE_H_
#define VALIDATEBINARYSEARCHTREE_H_

#include <limits>
using std::numeric_limits;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int lower = numeric_limits<int>::min();
        int upper = numeric_limits<int>::max();
        // return morrisInorder(root, lower);
        return recurPreorder(root, lower, upper);
    }

    bool recurPreorder(TreeNode *root, int lower, int upper) {
        if (!root) return true;
        int value = root->val;
        if (value <= lower || value >= upper) return false;
        return recurPreorder(root->left, lower, value) &&
               recurPreorder(root->right, value, upper);
    }

    bool recurInorder(TreeNode *root, int &pred) {
        if (!root) return true;
        if (!recurInorder(root->left, pred)) return false;
        if (root->val <= pred) return false;
        pred = root->val;
        return recurInorder(root->right, pred);
    }

    bool iterInorder(TreeNode *root, int pred) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (peakNode->val <= pred) return false;
                pred = peakNode->val;
                root = peakNode->right;

                stk.pop();
            }
        }

        return true;
    }

    bool morrisInorder(TreeNode *root, int pred) {
        bool isValidBST = true;
        while (root) {
            if (!root->left) {
                if (root->val <= pred) isValidBST = false;
                pred = root->val;

                root = root->right;
            }
            else {
                TreeNode *rightMost = root->left;
                while (rightMost->right && rightMost->right != root) {
                    rightMost = rightMost->right;
                }

                if (!rightMost->right) {
                    rightMost->right = root;
                    root = root->left;
                }
                else {
                    if (root->val <= pred) isValidBST = false;
                    pred = root->val;

                    rightMost->right = nullptr;
                    root = root->right;
                }
            }
        }

        return isValidBST;
    }
};

#endif /* VALIDATEBINARYSEARCHTREE_H_ */
