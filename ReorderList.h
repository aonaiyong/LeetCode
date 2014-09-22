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

#endif /* REORDERLIST_H_ */
