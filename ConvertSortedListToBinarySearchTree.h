/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    ConvertSortedListToBinarySearchTree.h
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution:   Bottom-up Recursion.
             Time: O(n), Space: O(log(n))
 */

#ifndef CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_
#define CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_

#include "TreeNode.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int n = getLength(head);
        return sortedListToBST(head, n);
    }

    TreeNode *sortedListToBST(ListNode *&head, int n) {
        if (n <= 0) return nullptr;

        TreeNode *left = sortedListToBST(head, n/2);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left;
        root->right = sortedListToBST(head, n-n/2-1);

        return root;
    }

    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }

        return len;
    }
};

#endif /* CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_ */
