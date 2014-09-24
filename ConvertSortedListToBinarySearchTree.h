/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    ConvertSortedListToBinarySearchTree.h
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution:   Bottom-up recursion.
 */

#ifndef CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_
#define CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_

#include "TreeNode.h"

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = getLength(head);
        return sortedListToBSTRecur(head, len);
    }

    TreeNode *sortedListToBSTRecur(ListNode *&head, int len) {
        if (len <= 0) return nullptr;

        int half = len / 2;
        TreeNode *left = sortedListToBSTRecur(head, half);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBSTRecur(head, len - half - 1);

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
