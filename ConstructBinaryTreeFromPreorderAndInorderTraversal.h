/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Construct Binary Tree from Pre-order and In-order Traversal
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 Notes:
 Given pre-order and in-order traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 Solution:   Recursion.
             Time: O(n^2), Space: O(n) (when the tree is skewed to the left)
             We can achieve O(n) time by using a hash table, which maps an element's value to its
             corresponding index in the in-order sequence.
 */

#ifndef CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_
#define CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_

#include <vector>
using std::vector;

#include <iterator>
using std::iterator;

#include <algorithm>
using std::find;

#include "TreeNode.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTree(vector<int>::const_iterator pbeg, vector<int>::const_iterator ibeg, int n) {
        if (n == 0) return nullptr;

        TreeNode *root = new TreeNode(*pbeg);
        int m = find(ibeg, ibeg + n, *pbeg) - ibeg;
        root->left = buildTree(pbeg + 1, ibeg, m);
        root->right = buildTree(pbeg + m + 1, ibeg + m + 1, n - m - 1);
        return root;
    }
};

#endif /* CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_ */
