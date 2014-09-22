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

// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        // find the (n+1)st node from the end of list
        ListNode *node = findNthFromEnd(&dummy, n + 1);
        if (!node) return head;
        ListNode *temp = node->next;
        node->next = temp->next;
        delete temp;

        return dummy.next;
    }

    // find the n-th node from the end of list
    // the last node is the first node from the end
    ListNode *findNthFromEnd(ListNode *head, int n) {
        if (n <= 0) return nullptr;

        ListNode *curr = head;
        while (n && curr) {
            --n;
            curr = curr->next;
        }
        if (n) return nullptr;

        ListNode *prev = head;
        while (curr) {
            prev = prev->next;
            curr = curr->next;
        }

        return prev;
    }
};

#endif /* REMOVENTHNODEFROMENDOFLIST_H_ */
