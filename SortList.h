/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Sort List
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/sort-list/
 Notes:
 Sort a linked list in O(n log n) time using constant space complexity.

 Solution:   MergeSort.
 */

#ifndef SORTLIST_H_
#define SORTLIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int n = getLength(head);
        return mergeSortList(head, n);
    }

    ListNode *mergeSortList(ListNode *&head, int n) {
        if (n <= 0) return nullptr;
        if (n == 1) {
            ListNode *single = head;
            head = head->next;
            single->next = nullptr;
            return single;
        }

        ListNode *head1 = mergeSortList(head, n/2);
        ListNode *head2 = mergeSortList(head, n - n/2);
        return mergeTwoLists(head1, head2);
    }

    int getLength(ListNode *head) {
        int n = 0;
        while (head) {
            ++n;
            head = head->next;
        }

        return n;
    }

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

#endif /* SORTLIST_H_ */
