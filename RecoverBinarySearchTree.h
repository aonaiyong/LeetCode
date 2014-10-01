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

#include <limits>
using std::numeric_limits;

#include <utility>
using std::swap;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode dummy(numeric_limits<int>::min()), *prev = &dummy;

        recurInorder(root, prev, first, second);
        if (first && second) swap(first->val, second->val);
    }

    void recurInorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        if (!root) return;

        recurInorder(root->left, prev, first, second);
        if (prev->val > root->val) {
            if (!second) first = prev;
            second = root;
        }
        prev = root;
        recurInorder(root->right, prev, first, second);
    }

    void iterInorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            }
            else {
                TreeNode *topNode = stk.top();
                if (prev->val > topNode->val) {
                    if (!second) first = prev;
                    second = topNode;
                }
                prev = topNode;

                root = topNode->right;
                stk.pop();
            }
        }
    }

    void morrisInorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        while (root) {
            if (!root->left) {      // left subtree is empty
                // process root
                if (prev->val > root->val) {
                    if (!second) first = prev;
                    second = root;
                }
                prev = root;

                root = root->right; // advance to right subtree
            }
            else {
                // find the rightmost node of the left subtree
                TreeNode *rightMost = root->left;
                while (rightMost->right && rightMost->right != root) {
                    rightMost = rightMost->right;
                }

                if (!rightMost->right) {      // left subtree is to be processed
                    rightMost->right = root;  // make root rightMost's right child
                    root = root->left;        // advance to left subtree
                }
                else {                        // left subtree is finished
                    // process root
                    if (prev->val > root->val) {
                        if (!second) first = prev;
                        second = root;
                    }
                    prev = root;

                    rightMost->right = nullptr; // restore rightMost's right child to nullptr
                    root = root->right;         // advance to right subtree
                }
            }
        }
    }
};

#endif /* RECOVERBINARYSEARCHTREE_H_ */
