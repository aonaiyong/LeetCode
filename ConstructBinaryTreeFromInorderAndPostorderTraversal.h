/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Construct Binary Tree from In-order and Post-order Traversal
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 Notes:
 Given in-order and post-order traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 Solution:   Recursion.
             Time: O(n^2), Space: O(n) (when the tree is skewed to the left)
             We can achieve O(n) time by using a hash table, which maps an element's value to its
             corresponding index in the in-order sequence.
 */

#ifndef CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_
#define CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <iterator>
using std::iterator;

#include "TreeNode.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), postorder.begin(), inorder.size());
    }

    TreeNode *buildTree(vector<int>::const_iterator ibeg, vector<int>::const_iterator pbeg, int n) {
        if (n == 0) return nullptr;

        TreeNode *root = new TreeNode(pbeg[n - 1]);
        int m = find(ibeg, ibeg + n, pbeg[n - 1]) - ibeg;
        root->left = buildTree(ibeg, pbeg, m);
        root->right = buildTree(ibeg + m + 1, pbeg + m, n - m - 1);
        return root;
    }
};

#endif /* CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_ */
