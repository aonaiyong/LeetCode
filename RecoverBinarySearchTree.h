/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 30, 2014
 Problem:    Recover Binary Search Tree
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/recover-binary-search-tree/
 Notes:
 Two elements of a binary search tree (BST) are swapped by mistake.

 Recover the tree without changing its structure.

 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

                                     swap 3&7
 Solution:   case A: 1 2 3 4 5 6 7 8 --------->  1 2 7 4 5 6 3 8
                                                      >     >
                                     swap 4&5
             case B: 1 2 3 4 5 6 7 8 --------->  1 2 3 5 4 6 7 8
                                                        >
             1. Recursive In-order Traversal.
                Time: O(n), Space: O(n).

             2. Iterative In-order Traversal.
                Time: O(n), Space: O(n).

             3. Morris In-order Traversal.
                Time: O(n), Space: O(1).
 */

#ifndef RECOVERBINARYSEARCHTREE_H_
#define RECOVERBINARYSEARCHTREE_H_

#include <climits>

#include <utility>
using std::swap;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode dummy(INT_MIN), *pred = &dummy;
        iterativeRecoverTree(root, pred, first, second);
        if (first && second)
            swap(first->val, second->val);
    }

    // Recursive In-order Traversal
    void recursiveRecoverTree(TreeNode *root, TreeNode *&pred, TreeNode *&first, TreeNode *&second) {
        if (!root) return;

        recursiveRecoverTree(root->left, pred, first, second);
        if (pred->val >= root->val) {
            if (!first)
                first = pred;
            second = root;
        }
        pred = root;
        recursiveRecoverTree(root->right, pred, first, second);
    }

    // Iterative In-order Traversal
    void iterativeRecoverTree(TreeNode *root, TreeNode *&pred, TreeNode *&first, TreeNode *&second) {
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                if (pred->val >= node->val) {
                    if (!first)
                        first = pred;
                    second = node;
                }
                pred = node;

                node = node->right;
                stk.pop();
            }
        }
     }

    // Morris In-order Traversal
    void morrisRecoverTree(TreeNode *root, TreeNode *&pred, TreeNode *&first, TreeNode *&second) {
        TreeNode *node = root;
        while (node) {
            if (!node->left) {      // left subtree is empty
                // process node
                if (pred->val > node->val) {
                    if (!second)
                        first = pred;
                    second = node;
                }
                pred = node;

                node = node->right; // advance to right subtree
            }
            else {
                // find the rightmost node of the left subtree
                TreeNode *rightMost = node->left;
                while (rightMost->right && rightMost->right != node)
                    rightMost = rightMost->right;

                if (!rightMost->right) {      // left subtree is to be processed
                    rightMost->right = node;  // make root rightMost's right child
                    node = node->left;        // advance to left subtree
                }
                else {                        // left subtree is finished
                    // process node
                    if (pred->val > node->val) {
                        if (!second)
                            first = pred;
                        second = node;
                    }
                    pred = node;

                    rightMost->right = nullptr; // restore rightMost's right child to nullptr
                    node = node->right;         // advance to right subtree
                }
            }
        }
    }
};

#endif /* RECOVERBINARYSEARCHTREE_H_ */
