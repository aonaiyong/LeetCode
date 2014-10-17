/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 24, 2014
 Problem:    Merge Sort List
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/sort-list/
 Notes:
 Sort a linked list in O(n log n) time using constant space complexity.

 Solution:   MergeSort.
             http://en.wikipedia.org/wiki/Merge_sort
             http://www.sorting-algorithms.com/merge-sort

             1. Top-down recursion with size parameter.
                The recursion tree is right-leaning.

             2. Top-down recursion with two index limits parameters.
                The recursion tree is left-leaning.

             Time: O(nlogn), Space: O(logn) for recursion
 */

#ifndef MERGESORTLIST_H_
#define MERGESORTLIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int n = getLength(head);
        return mergeSortList(head, n);
//        return mergeSortList(head, 0, n-1);
    }

    ListNode *mergeSortList(ListNode *&head, int n) {
        if (n <= 0)
        	return nullptr;
        if (n == 1) {
            ListNode *single = head;
            head = head->next;
            single->next = nullptr;
            return single;
        }

        int m = n/2;
        ListNode *head1 = mergeSortList(head, m);
        ListNode *head2 = mergeSortList(head, n - m);
        return mergeTwoLists(head1, head2);
    }

    // Both p and r are inclusive
    ListNode *mergeSortList(ListNode *&head, int p, int r) {
        if (p > r)
        	return nullptr;
        if (p == r) {
            ListNode *single = head;
            head = head->next;
            single->next = nullptr;
            return single;
        }

        int q = p + (r - p) / 2;
        ListNode *head1 = mergeSortList(head, p, q);
        ListNode *head2 = mergeSortList(head, q+1, r);
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

#endif /* MERGESORTLIST_H_ */
