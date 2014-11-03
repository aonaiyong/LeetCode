/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Reverse Nodes in k-Group
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.

 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5

 For k = 3, you should return: 3->2->1->4->5

 Solution:   Two pointer.
 */

#ifndef REVERSENODESINK_GROUP_H_
#define REVERSENODESINK_GROUP_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1)
            return head;

        // number of k-groups need to be reversed
        int ngroup = getLength(head) / k;
        if (ngroup < 1)
            return head;

        // prev -> end of last k-Group
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        for (int i = 0; i < ngroup; ++i) {
            ListNode *first = prev->next;
            for (int j = 0; j < k - 1; ++j) {
                ListNode *second = first->next;
                first->next = second->next;
                second->next = prev->next;
                prev->next = second;
            }
            prev = first;
        }
        return dummy.next;
    }

    int getLength(ListNode *head) {
        int n = 0;
        while (head) {
            ++n;
            head = head->next;
        }
        return n;
    }
};

#endif /* REVERSENODESINK_GROUP_H_ */
