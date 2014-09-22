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

// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return nullptr;

        ListNode dummy(0), *tail = head;
        dummy.next = head;
        while (tail->next) {
            ListNode *temp = tail->next;
            if (tail->val <= temp->val) {
                tail = temp;
            }
            else {
                ListNode *curr = &dummy;
                while (curr->next->val <= temp->val) {
                    curr = curr->next;
                }

                tail->next = temp->next;
                temp->next = curr->next;
                curr->next = temp;
            }
        }

        return dummy.next;
    }
};

#endif /* INSERTIONSORTLIST_H_ */
