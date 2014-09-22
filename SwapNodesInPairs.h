/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Swap Nodes in Pairs
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/swap-nodes-in-pairs/
 Notes:
 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 Solution:   Two pointers.
 */

#ifndef SWAPNODESINPAIRS_H_
#define SWAPNODESINPAIRS_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        ListNode *curr = head;
        while (curr && curr->next) {
            ListNode *temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;

            prev = curr;
            curr = curr->next;
        }
        return dummy.next;
    }
};

#endif /* SWAPNODESINPAIRS_H_ */
