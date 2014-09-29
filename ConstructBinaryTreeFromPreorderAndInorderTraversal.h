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

#include "TreeNode.h"

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recursiveBuildTree(preorder.cbegin(), inorder.cbegin(), preorder.size());
    }

    TreeNode *recursiveBuildTree(vector<int>::const_iterator pbeg, vector<int>::const_iterator ibeg, int n) {
        if (n <= 0) return nullptr;

        int val = *pbeg;
        int mid = 0;
        while (ibeg[mid] != val) ++mid;

        TreeNode *root = new TreeNode(val);
        root->left = recursiveBuildTree(pbeg + 1, ibeg, mid);
        root->right = recursiveBuildTree(pbeg + mid + 1, ibeg + mid + 1, n - mid - 1);
        return root;
    }
};

#endif /* CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_ */
