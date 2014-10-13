/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Insertion Sort List
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/insertion-sort-list/
 Notes:
 Sort a linked list using insertion sort.

 Solution:   Insertion Sort. http://en.wikipedia.org/wiki/Insertion_sort
 */

#ifndef INSERTIONSORTLIST_H_
#define INSERTIONSORTLIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return nullptr;

        ListNode dummy(0), *tail = head;
        dummy.next = head;
        while (tail->next) {
            ListNode *curr = tail->next;
            if (tail->val <= curr->val)
                tail = tail->next;
            else {
                ListNode *node = &dummy;
                while (node->next->val <= curr->val)
                    node = node->next;
                tail->next = curr->next;
                curr->next = node->next;
                node->next = curr;
            }

            // ListNode *curr = tail->next;
            // ListNode *node = &dummy;
            // while (node != tail && node->next->val <= curr->val)
            //     node = node->next;

            // if (node == tail)
            //     tail = tail->next;
            // else {
            //     tail->next = curr->next;
            //     curr->next = node->next;
            //     node->next = curr;
            // }
        }
        return dummy.next;
    }
};

#endif /* INSERTIONSORTLIST_H_ */
