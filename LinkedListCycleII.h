/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Linked List Cycle II
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/linked-list-cycle-ii/
 Notes:
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

 Follow up:
 Can you solve it without using extra space?

 Solution:   Two pointers.
 */

#ifndef LINKEDLISTCYCLEII_H_
#define LINKEDLISTCYCLEII_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;

        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

#endif /* LINKEDLISTCYCLEII_H_ */
