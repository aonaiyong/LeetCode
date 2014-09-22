/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Duplicates fromSorted List
 Difficulty: 1
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
 Notes:

 Given a sorted linked list, delete all duplicates such that each element appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

 Solution:
 */

#ifndef REMOVEDUPLICATESFROMSORTEDLIST_H_
#define REMOVEDUPLICATESFROMSORTEDLIST_H_

// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *curr = head;
        while (curr->next) {
            ListNode *temp = curr->next;
            if (curr->val != temp->val) {
                curr = temp;
            }
            else {
                curr->next = temp->next;
                delete temp;
            }
        }

        return head;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDLIST_H_ */
