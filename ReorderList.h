/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Reorder List
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/reorder-list/
 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...

 You must do this in-place without altering the nodes' values.

 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Solution:   Two pointers.
 */

#ifndef REORDERLIST_H_
#define REORDERLIST_H_

#include "ListNode.h"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next)
            return;

        // find the middle node
        ListNode *mid = findMiddle(head);
        // reverse the second half
        ListNode *head2 = reverse(mid->next);
        mid->next = nullptr;
        head = interleave(head, head2);
    }

    // find the middle node
    ListNode *findMiddle(ListNode *head) {
        if (!head || !head->next)
            return head;

        // Note that we have to skip the nullptr node at the end of list
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // reverse the list
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        while (head->next) {
            ListNode *move = head->next;
            head->next = move->next;
            move->next = dummy.next;
            dummy.next = move;
        }
        return dummy.next;
    }

    // interleave nodes in the lists
    ListNode *interleave(ListNode *l1, ListNode *l2) {
        int i = 1;
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            ListNode *&node = i++ % 2 ? l1 : l2;
            tail = tail->next = node;
            node = node->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

#endif /* REORDERLIST_H_ */
