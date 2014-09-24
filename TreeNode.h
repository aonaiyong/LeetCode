/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Tree Node Class
 Difficulty:
 Source:
 Notes:

 Solution:
 */

#ifndef TREENODE_H_
#define TREENODE_H_

// Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif /* TREENODE_H_ */
