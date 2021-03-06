/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Remove Duplicates from Sorted ListII
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution:   Check consecutive nodes (a window). If they have differing values, add the first node into
             current result and advance the window; Otherwise, delete all nodes have that value. Note
             that in the end, there might be only one node in the window. In this case, we simply update
             the result and advance the window.

             Time: O(n), Space: O(1)
 */

#ifndef REMOVEDUPLICATESFROMSORTEDLISTII_H_
#define REMOVEDUPLICATESFROMSORTEDLISTII_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
        	return head;

        ListNode dummy(0), *tail = &dummy;
        dummy.next = head;
        while (tail->next) {
            ListNode *curr = tail->next;
            int value = curr->val;

            // check consecutive nodes
            if (!curr->next || curr->next->val != value)
                tail = curr;
            else { // duplicates to be deleted
                while (curr && curr->val == value) {
                    tail->next = curr->next;
                    delete curr;

                    curr = tail->next;
                }
            }
        }
        return dummy.next;
    }
};

#endif /* REMOVEDUPLICATESFROMSORTEDLISTII_H_ */
