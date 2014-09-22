/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Merge k Sorted Lists
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/merge-k-sorted-lists/
 Notes:

 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

 Solution:   1. Min priority queue.
                O(k*n*log(k)) time, O(log(k)) space.

             2. Divide-and-Conquer.
                O(k*n*log(k)) time, O(1) space.
 */

#ifndef MERGEKSORTEDLISTS_H_
#define MERGEKSORTEDLISTS_H_

#include <vector>
using std::vector;

#include <queue>
using std::priority_queue;

// Definition for singly-linked list.
 struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Compare {
public:
    bool operator()(ListNode *x, ListNode *y) const {
        return x->val > y->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsDQ(lists);
    }

    // Min Priority Queue: O(n*k*log(k)) time, O(log(k)) space
    ListNode *mergeKListsMPQ(vector<ListNode *> &lists) {
       priority_queue<ListNode *, vector<ListNode *>, Compare> q;

       // build a heap of size k
       // O(k) time complexity, O(k) space complexity
       for (int i = 0; i < lists.size(); ++i) {
           if (lists[i]) {
               q.push(lists[i]);
           }
       }

       ListNode dummy(0), *curr = &dummy;
       while (!q.empty()) {        // n * k steps
           curr->next = q.top();   // O(1) time
           curr = curr->next;
           q.pop();                // O(log(k)) time

           if (curr->next) {
               q.push(curr->next); // O(log(k)) time
           }
       }

       return dummy.next;
    }

    // Divide-and-Conquer: O(n*k*log(k)) time, O(1) space
    ListNode *mergeKListsDQ(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;

        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k / 2; ++i) {
                lists[i] = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
            }

            int i = k / 2;
            if (k % 2) {
                ++i;
                lists[i-1] = lists[k-1];
            }
            k = i;
        }

        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *curr = &dummy;
        while (l1 && l2) {
            ListNode *&min = l1->val <= l2->val ? l1 : l2;
            curr->next = min;
            min = min->next;
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

#endif /* MERGEKSORTEDLISTS_H_ */
