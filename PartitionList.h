/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Partition List
 Difficulty: 3
 Source:     https://github.com/aonaiyong/LeetCode
 Notes:
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

 You should preserve the original relative order of the nodes in each of the two partitions.

 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

 Solution:   1. First decouple nodes into two lists, and then splice the lists.
             2. Partition in place.
 */

#ifndef PARTITIONLIST_H_
#define PARTITIONLIST_H_

#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        return partitionDecouple(head, x);
    }

    // succinct but maybe less efficient
    ListNode *partitionDecouple(ListNode *head, int x) {
        ListNode leftDummy(0), rightDummy(0);
        ListNode *left = &leftDummy, *right = &rightDummy;
        // decouple nodes < x and nodes >= x, respectively
        while (head) {
            if (head->val < x) {
                left = left->next = head;
            }
            else {
                right = right->next = head;
            }

            head = head->next;
        }

        // splice the two lists
        left->next = rightDummy.next;
        right->next = nullptr;
        return leftDummy.next;
    }

    // verbose
    ListNode *partitionInPlace(ListNode *head, int x) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *less = &dummy, *greater = &dummy;
        while (greater->next) {
            ListNode *temp = greater->next;
            if (x <= temp->val) {
                greater = temp;
            }
            else {
                if (less == greater) { // "greater part" is empty
                    less = greater = temp;
                }
                else {
                    greater->next = temp->next;
                    temp->next = less->next;
                    less->next = temp;
                    less = temp;
                }
            }
        }

        return dummy.next;
    }
};

#endif /* PARTITIONLIST_H_ */
