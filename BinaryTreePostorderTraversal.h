/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 28, 2014
 Problem:    Binary Tree Post-order Traversal
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 Notes:
 Given a binary tree, return the post-order traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].

 Note: Recursive solution is trivial, could you do it iteratively?

 Solution:  http://en.wikipedia.org/wiki/Tree_traversal
             1. Recursive Post-order Traversal.
                Time: O(n), Space: O(n)

             2. Iterative Post-order Traversal (Stack).
                Time: O(n), Space: O(n)

             3. Morris Post-order Traversal.
                Time: O(n), Space: O(1)

                For 1&2, each edge is traversed exactly once.
                For 3, each edge is traversed at most 3 times.
 */

#ifndef BINARYTREEPOSTORDERTRAVERSAL_H_
#define BINARYTREEPOSTORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> values;
        iterativePostorder(root, values);
        return values;
    }

    // Recursive Post-order Traversal
    void recursivePostorder(TreeNode *root, vector<int> &values) {
        if (!root) return;

        recursivePostorder(root->left, values);
        recursivePostorder(root->right, values);
        values.push_back(root->val);
    }

    // Iterative Post-order Traversal
    void iterativePostorder(TreeNode *root, vector<int> &values) {
        stack<TreeNode *> stk;
        TreeNode *node = root, *lastNodeVisited = nullptr;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (!peakNode->right || peakNode->right == lastNodeVisited) {
                    values.push_back(peakNode->val);
                    lastNodeVisited = peakNode;
                    stk.pop();
                }
                else
                    node = peakNode->right;
            }
        }
    }

    // Morris Post-order Traversal
    void morrisPostorder(TreeNode *root, vector<int> &vals) {
        // dummy is new root
        TreeNode dummy(0), *node = &dummy;
        dummy.left = root; dummy.right = nullptr;

        while (node) {
            if (!node->left) {      // left subtree is empty
                node = node->right; // advance to right subtree
            }
            else {
                // find rightmost node of left subtree
                TreeNode *rightMost = node->left;
                while (rightMost->right && rightMost->right != node) {
                    rightMost = rightMost->right;
                }

                if (!rightMost->right) {    // left subtree is to be processed
                    rightMost->right = node;// make node rightMost's right child
                    node = node->left;      // advance to left subtree
                }
                else {
                    // print in reverse order the nodes on the path
                    // from root of left subtree to rightmost node of left subtree
                    morrisReversePrint(rightMost, node->left, vals);
                    rightMost->right = nullptr;
                    node = node->right;
                }
            }
        }
    }

    void morrisReversePrint(TreeNode *src, TreeNode *dst, vector<int> &vals) {
        morrisReversePath(dst, src); // reverse the path from dst to src

        TreeNode *node = src;
        while (true) {
            vals.push_back(node->val);
            if (node == dst)
                break;
            node = node->right;
        }

        morrisReversePath(src, dst); // reverse back
    }

    void morrisReversePath(TreeNode *src, TreeNode *dst) {
        if (src == dst)
            return;

        TreeNode *node = src->right;
        while (true) {
            TreeNode *next = node->right;
            node->right = src;
            src = node;
            node = next;

            if (src == dst)
                return;
        }
    }
};

#endif /* BINARYTREEPOSTORDERTRAVERSAL_H_ */
