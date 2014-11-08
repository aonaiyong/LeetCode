/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 28, 2014
 Problem:    Binary Tree Preorder Traversal
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 Notes:
 Given a binary tree, return the pre-order traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].

 Note: Recursive solution is trivial, could you do it iteratively?

 Solution:   http://en.wikipedia.org/wiki/Tree_traversal
             1. Recursive Pre-order Traversal.
                Time: O(n)   (to be exact, 2n)
                Space: O(n)  (left-skewed binary tree)

             2. Iterative Pre-order Traversal (Stack).
                Time: O(n)   (to be exact, 2n and n for method 1 and 2, respetively)
                Space: O(n)  (left-skewed binary tree)

             3. Morris Pre-order Traversal.
                Time: O(n), Space: O(1)
                Note that we have to fully traverse the tree to recover it.

                For 1&2, each edge is traversed exactly once.
                For 3, each edge is traversed at most 3 times.
 */

#ifndef BINARYTREEPREORDERTRAVERSAL_H_
#define BINARYTREEPREORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> values;
        iterativePreorder(root, values);
        return values;
    }

    // Recursive Pre-order Traversal
    void recursivePreorder(TreeNode *root, vector<int> &values) {
        if (!root)
            return;

        values.push_back(root->val);
        recursivePreorder(root->left, values);
        recursivePreorder(root->right, values);
    }

    // Iterative Pre-order Traversal
    void iterativePreorder(TreeNode *root, vector<int> &values) {
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (node || !stk.empty()) {
            if (node) {
                values.push_back(node->val);

                stk.push(node);          // stk.push(node->right);
                node = node->left;
            }
            else {
                node = stk.top()->right; // node = stk.top();
                stk.pop();
            }
        }
    }

    // Iterative Pre-order Traversal Method 2
    void iterativePreorder2(TreeNode *root, vector<int> &values) {
        stack<TreeNode *> stk;
        if (root)
            stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            values.push_back(node->val);
            if (node->right)
                stk.push(node->right);
            if (node->left)
                stk.push(node->left);
        }
    }

    // Morris Pre-order Traversal
    void morrisPreorder(TreeNode *root, vector<int> &vals) {
        TreeNode *node = root;
        while (node) {
            if (!node->left) { // left subtree is empty
                vals.push_back(node->val); // process node

                node = node->right;        // advance to right subtree
            }
            else {
                // find the rightmost node of the left subtree
                TreeNode *rightMost = node->left;
                while (rightMost->right && rightMost->right != node)
                    rightMost = rightMost->right;

                if (!rightMost->right) {       // left subtree is to be processed
                    vals.push_back(node->val); // process node

                    rightMost->right = node;   // make node rightMost's right child
                    node = node->left;         // advance to left subtree
                }
                else {                         // left subtree is finished
                    rightMost->right = nullptr;// restore rightMost's right child to nullptr
                    node = node->right;        // advance to right subtree
                }
            }
        }
    }
};

#endif /* BINARYTREEPREORDERTRAVERSAL_H_ */
