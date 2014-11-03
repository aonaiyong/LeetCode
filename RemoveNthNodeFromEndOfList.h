/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Nth Node From End of List
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.

 For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution:   Two pointers.
 */

#ifndef REMOVENTHNODEFROMENDOFLIST_H_
#define REMOVENTHNODEFROMENDOFLIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        // find the (n+1)st node from the end of list
        ListNode *node = findNthFromEnd(&dummy, n + 1);
        if (!node)
            return head;
        ListNode *del = node->next;
        node->next = del->next;
        delete del;
        return dummy.next;
    }

    // find the n-th node from the end of list
    // the last node counts as the first node from the end
    ListNode *findNthFromEnd(ListNode *head, int n) {
        ListNode *front = head, *back = head;
        while (n > 0 && front) {
            --n;
            front = front->next;
        }
        if (n > 0)
            return nullptr;
        while (front) {
            back = back->next;
            front = front->next;
        }
        return back;
    }
};

#endif /* REMOVENTHNODEFROMENDOFLIST_H_ */
