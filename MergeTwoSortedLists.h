/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Merge Two Sorted Lists
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/merge-two-sorted-lists/
 Notes:
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

 Solution:   Use dummy node.
 */

#ifndef MERGETWOSORTEDLISTS_H_
#define MERGETWOSORTEDLISTS_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 && l2) {
            ListNode *&min = l1->val <= l2->val ? l1 : l2;
            tail->next = min;
            tail = tail->next;

            min = min->next;
        }
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

#endif /* MERGETWOSORTEDLISTS_H_ */
