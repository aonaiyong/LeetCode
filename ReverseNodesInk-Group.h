/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Reverse Nodes in k-Group
 Difficulty:
 Source:
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
        if (k <= 1) return head;

        // calculate how many reverses need done
        int len = getLength(head);
        int times = len / k;
        if (!times) return head;

        ListNode dummy(0);
        dummy.next = head;
        // prev -> tail of last k-Group
        // curr -> head of current k-Group
        ListNode *prev = &dummy, *curr = head;
        for (int i = 0; i < times; ++i) {
            // insert k-1 nodes between prev and tail
            for (int j = 0; j < k - 1; ++j) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
            }

            // advance to next group
            prev = curr;
            curr = curr->next;
        }

        return dummy.next;
    }

    // calculate number of nodes in the list
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
};

#endif /* REVERSENODESINK_GROUP_H_ */
