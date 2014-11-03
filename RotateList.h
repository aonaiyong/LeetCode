/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Rotate List
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/rotate-list/
 Notes:
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->nullptr and k = 2,
 return 4->5->1->2->3->nullptr.

 Solution:   Two pointers.
 */

#ifndef ROTATELIST_H_
#define ROTATELIST_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return nullptr;

        // find tail node and calculate size of list
        ListNode *tail = head;
        int n = 1;
        while (tail->next) {
            ++n;
            tail = tail->next;
        }
        k %= n;
        if (!k)
            return head;

        // find the (k+1)st node from the end of list
        ListNode *newTail = head;
        for (int i = 0; i < n - k - 1; ++i) {
            newTail = newTail->next;
        }
        tail->next = head;
        head = newTail->next;
        newTail->next = nullptr;
        return head;
    }
};

#endif /* ROTATELIST_H_ */
