/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 30, 2014
 Problem:    Binary Tree Maximum Path Sum
 Difficulty:
 Source:
 Notes:
 Given a binary tree, find the maximum path sum.

 The path may start and end at any node in the tree.

 For example:
 Given the below binary tree,

        1
       / \
      2   3
 Return 6.

 Solution:   Recursion.
 */

#ifndef BINARYTREEMAXIMUMPATHSUM_H_
#define BINARYTREEMAXIMUMPATHSUM_H_

#include <limits>
using std::numeric_limits;

#include <algorithm>
using std::max;

#include "TreeNode.h"

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int globalMax = numeric_limits<int>::min();
        maxPathSum(root, globalMax);
        return globalMax;
    }

    int maxPathSum(TreeNode *root, int &globalMax) {
        if (!root) return 0;

        int leftMax = maxPathSum(root->left, globalMax);
        int rightMax = maxPathSum(root->right, globalMax);

        int rootMax = max(root->val, root->val + max(leftMax, rightMax));
        globalMax = max(globalMax, rootMax);
        globalMax = max(globalMax, root->val + leftMax + rightMax);

        return rootMax;
    }
};

#endif /* BINARYTREEMAXIMUMPATHSUM_H_ */
