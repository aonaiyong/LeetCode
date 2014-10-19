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

 Solution:   Two pointers.
             Property of result list: strictly increasing.

             Time: O(n), Space: O(1)
 */

#ifndef REMOVEDUPLICATESFROMSORTEDLIST_H_
#define REMOVEDUPLICATESFROMSORTEDLIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
        	return head;

        ListNode *tail = head;
        while (tail->next) {
            ListNode *curr = tail->next;
            if (tail->val != curr->val)
                tail = curr;
            else {
                tail->next = curr->next;
                delete curr;
            }
        }
        return head;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDLIST_H_ */
