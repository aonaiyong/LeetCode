/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Reverse Linked List II
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/reverse-linked-list-ii/
 Notes:
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,

 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.

 Solution:   Two pointers.
 */

#ifndef REVERSELINKEDLISTII_H_
#define REVERSELINKEDLISTII_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        // find position m - 1
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        // reverse nodes from position m + 1 to n
        ListNode *curr = prev->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};

#endif /* REVERSELINKEDLISTII_H_ */
