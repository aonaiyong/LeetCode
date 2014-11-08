/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 28, 2014
 Problem:    Binary Tree In-order Traversal
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 Notes:
 Given a binary tree, return the in-order traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,3,2].

 Note: Recursive solution is trivial, could you do it iteratively?

 Solution:   http://en.wikipedia.org/wiki/Tree_traversal
             1. Recursive In-order Traversal.
                Time: O(n)   (to be exact, 2n)
                Space: O(n)  (left-skewed binary tree)

             2. Iterative In-order Traversal (Stack).
                Time: O(n)   (to be exact, 2n)
                Space: O(n)  (left-skewed binary tree)

             3. Morris In-order Traversal.
                Time: O(n), Space: O(1)
                Note that we have to fully traverse the tree to recover it.

                For 1&2, each edge is traversed exactly once.
                For 3, each edge is traversed at most 3 times.
 */

#ifndef BINARYTREEINORDERTRAVERSAL_H_
#define BINARYTREEINORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> values;
        morrisInorder(root, values);
        return values;
    }

    void recursiveInorder(TreeNode *root, vector<int> &values) {
        if (!root) return;

        recursiveInorder(root->left, values);
        values.push_back(root->val);
        recursiveInorder(root->right, values);
    }

    void iterativeInorder(TreeNode *root, vector<int> &values) {
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                stk.pop();

                values.push_back(node->val);
                node = node->right;
            }
        }
    }

    void morrisInorder(TreeNode *root, vector<int> &vals) {
        TreeNode *node = root;
        while (node) {
            if (!node->left) {             // left subtree is empty
                vals.push_back(node->val); // process node

                node = node->right;        // advance to right subtree
            }
            else {
                // find the rightmost node of the left subtree
                TreeNode *rightMost = node->left;
                while (rightMost->right && rightMost->right != node)
                    rightMost = rightMost->right;

                if (!rightMost->right) {        // left subtree is to be processed
                    rightMost->right = node;    // make node rightMost's right child
                    node = node->left;          // advance to left subtree
                }
                else {                          // left subtree is finished
                    vals.push_back(node->val);  // process node

                    rightMost->right = nullptr; // restore rightMost's right child to nullptr
                    node = node->right;         // advance to right subtree
                }
            }
        }
    }
};

#endif /* BINARYTREEINORDERTRAVERSAL_H_ */
