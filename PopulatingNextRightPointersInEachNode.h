/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Populating Next Right Pointers in Each Node
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 Notes:
 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.

 Note:

 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
          1
        /  \
       2    3
      / \  / \
     4  5  6  7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \  / \
     4->5->6->7 -> NULL

 Solution:   1. Iterative with Queue.
                Time: O(n), Space: O(n)
             2. Iterative with two while loops (level by level)
                Time: O(n), Space: O(1)
             3. Recursive.
                Time: O(n), Space: O(log(n))
 */

#ifndef POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_
#define POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_

#include <queue>
using std::queue;

#include "TreeNode.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        iterativeConnect(root);
    }

    void iterativeQueueConnect(TreeLinkNode *root) {
        queue<TreeLinkNode *> frontier;
        if (root) frontier.push(root);
        while (!frontier.empty()) {
            TreeLinkNode *prev = nullptr, *curr = nullptr;
            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                curr = frontier.front();
                if (prev)
                    prev->next = curr;
                prev = curr;
                if (curr->left) frontier.push(curr->left);
                if (curr->right) frontier.push(curr->right);
                frontier.pop();
            }
        }
    }

    void iterativeConnect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *node = root;
        while (node->left) {
            TreeLinkNode *level = node;
            while (level) {
                level->left->next = level->right;
                level->right->next = level->next ? level->next->left : nullptr;
                level = level->next;
            }
            node = node->left;
        }
    }

    void recursiveConnect(TreeLinkNode *root) {
         if (!root || !root->left || !root->right) return;

         root->left->next = root->right;
         root->right->next = root->next ? root->next->left : nullptr;
         recursiveConnect(root->left);
         recursiveConnect(root->right);
     }
};

#endif /* POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_ */
