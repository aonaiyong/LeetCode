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

 Solution:   Two pointers.
 */

#ifndef PARTITIONLIST_H_
#define PARTITIONLIST_H_

// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) return head;

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
