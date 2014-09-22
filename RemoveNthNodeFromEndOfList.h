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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // find the middle node
        ListNode *mid = findMidNode(head);
        // reverse the second half
        mid->next = reverse(mid->next);

        // insert the second half into the first half
        ListNode *curr = head;
        while (curr != mid) {
            ListNode *temp = mid->next;
            mid->next = temp->next;
            temp->next = curr->next;
            curr->next = temp;

            curr = temp->next;
        }
    }

    // reverse the list
    ListNode *reverse(ListNode *head) {
        if (!head) return nullptr;

        ListNode dummy(0);
        dummy.next = head;
        while (head->next) {
            ListNode *temp = head->next;
            head->next = temp->next;
            temp->next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;
    }

    // find the middle node
    ListNode *findMidNode(ListNode *head) {
        if (!head) return nullptr;

        // Note that we have to skip the nullptr node at the end of list
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

#endif /* REMOVENTHNODEFROMENDOFLIST_H_ */
