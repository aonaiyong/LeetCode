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
        if (!head || !head->next) return head;
        int len = getLength(head);
        return mergeSortList(head, len);
    }

    ListNode *mergeSortList(ListNode *&head, int len) {
        if (len == 0) return nullptr;
        if (len == 1) {
            ListNode *temp = head;
            head = head->next;
            temp->next = nullptr; // create single node list
            return temp;
        }

        int half = len / 2;
        ListNode *head1 = mergeSortList(head, half);
        ListNode *head2 = mergeSortList(head, len - half);

        return mergeTwoLists(head1, head2);
    }


    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
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
