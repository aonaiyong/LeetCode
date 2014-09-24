/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Convert Sorted Array To Binary Search Tree
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 Notes:
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution:   DFS.
 */

#ifndef CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_
#define CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_

#include <vector>
using std::vector;

#include "TreeNode.h"

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBSTRecur(num, 0, num.size() - 1);
    }

    TreeNode *sortedArrayToBSTRecur(vector<int> &num, int low, int top) {
        if (top < low) return nullptr;

        int mid = low + (top - low) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBSTRecur(num, low, mid - 1);
        root->right = sortedArrayToBSTRecur(num, mid + 1, top);
        return root;
    }
};

#endif /* CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_ */
