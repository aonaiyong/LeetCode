/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 29, 2014
 Problem:    Populating Next Right Pointers in Each Node II
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 Notes:
 Follow up for problem "Populating Next Right Pointers in Each Node".

 What if the given tree could be any binary tree? Would your previous solution still work?

 Note:

 You may only use constant extra space.
 For example,
 Given the following binary tree,
          1
        /  \
       2    3
      / \    \
     4   5    7
 After calling your function, the tree should look like:
          1 -> NULL
        /  \
       2 -> 3 -> NULL
      / \    \
     4-> 5 -> 7 -> NULL

 Solution: 1. Iterative with Queue.
              Time: O(n), Space: O(n)
           2. Iterative with two while loops (level by level).
              Time: O(n), Space: O(1)
           3. Recursive.
              Time: O(n), Space: O(n)
 */

#ifndef POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_
#define POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_

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
            TreeLinkNode dummy(0), *node = &dummy;
            int n = frontier.size();
            for (int i = 0; i < n; ++i) {
                node = node->next = frontier.front();
                if (node->left) frontier.push(node->left);
                if (node->right) frontier.push(node->right);

                frontier.pop();
            }
        }
    }

    void iterativeConnect(TreeLinkNode *root) {
        TreeLinkNode *node = root;
        while (node) {
            TreeLinkNode dummy(0), *prev = &dummy;
            while (node) {
                if (node->left)
                    prev = prev->next = node->left;
                if (node->right)
                    prev = prev->next = node->right;
                node = node->next;
            }
            node = dummy.next;
        }
    }

    void recursiveConnect(TreeLinkNode *root) {
         if (!root) return;

         TreeLinkNode dummy(0), *prev = &dummy;
         while (root) {
             if (root->left)
                 prev = prev->next = root->left;
             if (root->right)
                 prev = prev->next = root->right;
             root = root->next;
         }
         recursiveConnect(dummy.next);
     }
};

#endif /* POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_ */
