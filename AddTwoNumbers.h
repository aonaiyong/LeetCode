/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Add Two Numbers
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/add-two-numbers/
 Notes:
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution:   Math.
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

#include "ListNode.h"

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail = tail->next = new ListNode(sum % 10);
        }
        return dummy.next;
    }
};

#endif /* ADDTWONUMBERS_H_ */
