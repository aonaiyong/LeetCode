/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Linked List Cycle
 Difficulty: 2
 Source:     https://oj.leetcode.com/problems/linked-list-cycle/
 Notes:
 Given a linked list, determine if it has a cycle in it.

 Follow up:
 Can you solve it without using extra space?

 Solution:   Two pointers.
 */

#ifndef LINKEDLISTCYCLE_H_
#define LINKEDLISTCYCLE_H_

// Definition for singly-linked list.
 struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

 class Solution {
 public:
     bool hasCycle(ListNode *head) {
         if (!head || !head->next) return false;

         ListNode *slow = head, *fast = head;
         while (fast && fast->next) {
             slow = slow->next;
             fast = fast->next->next;

             if (slow == fast) return true;
         }
         return false;
     }
 };

#endif /* LINKEDLISTCYCLE_H_ */
