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

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        return partitionDecouple(head, x);
    }

    // succinct but maybe less efficient
    ListNode *partitionDecouple(ListNode *head, int x) {
    	ListNode dummy1(0), *tail1 = &dummy1;
    	ListNode dummy2(0), *tail2 = &dummy2;
        // decouple nodes < x and nodes >= x, respectively
        while (head) {
            if (head->val < x)
                tail1 = tail1->next = head;
            else
                tail2 = tail2->next = head;

            head = head->next;
        }
        // splice the two lists
        tail1->next = dummy2.next;
        tail2->next = nullptr;     // important

        return dummy1.next;
    }

    // verbose
    ListNode *partitionInPlace(ListNode *head, int x) {
        ListNode dummy(0), *less = &dummy, *greater = &dummy;
        dummy.next = head;
        while (greater->next) {
            ListNode *curr = greater->next;
            if (x <= curr->val)
                greater = curr;
            else {
                if (less == greater)  // "greater part" is empty
                    less = greater = curr;
                else {
                    greater->next = curr->next;
                    curr->next = less->next;
                    less = less->next = curr;
                }
            }
        }

        return dummy.next;
    }
};

#endif /* PARTITIONLIST_H_ */
