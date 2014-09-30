/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    PathSumII.h
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/path-sum-ii/
 Notes:
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
 return
 [
    [5,4,11,2],
    [5,8,4,5]
 ]

 Solution:  1. Recursive solution.
                Time: O(n), Space: O(n).

            2. Iterative post-order traversal.
                Time: O(n), Space: O(n).
 */

#ifndef PATHSUMII_H_
#define PATHSUMII_H_

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include "TreeNode.h"

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int>> all;
        iterativePathSum(root, sum, path, all);
        return all;
    }

    void recursivePathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &all) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (root->val == sum) {
                path.push_back(root->val);
                all.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);
        recursivePathSum(root->left, sum - root->val, path, all);
        recursivePathSum(root->right, sum - root->val, path, all);
        path.pop_back();
    }


    void iterativePathSum(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &all) {
        stack<TreeNode *> stk;
        TreeNode *lastNodeVisited = nullptr;
        while (root || !stk.empty()) {
            if (root) {
                sum -= root->val;
                path.push_back(root->val);
                stk.push(root);

                root = root->left;
            }
            else {
                TreeNode *peakNode = stk.top();
                if (!peakNode->right || peakNode->right == lastNodeVisited) {
                    if (!peakNode->right && !peakNode->left && !sum) {
                        all.push_back(path);
                    }

                    lastNodeVisited = peakNode;
                    sum += peakNode->val;
                    path.pop_back();
                    stk.pop();
                }
                else {
                    root = peakNode->right;
                }
            }
        }
    }
};

#endif /* PATHSUMII_H_ */
