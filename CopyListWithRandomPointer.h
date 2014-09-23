/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    Copy List with Random Pointer
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 Notes:
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

 Return a deep copy of the list.

 Solution:  1. Three passes.
               3 * n steps, O(1) space.
            2. Hash.
               n steps, O(n) space.
 */

#ifndef COPYLISTWITHRANDOMPOINTER_H_
#define COPYLISTWITHRANDOMPOINTER_H_

#include <unordered_map>
using std::unordered_map;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomListThreePass(head);
    }

    // 3 * n steps, O(1) space
    RandomListNode *copyRandomListThreePass(RandomListNode *head) {
        // 1st pass: for each node in the list, create a copy right after it
        RandomListNode *curr = head;
        while (curr) {
            RandomListNode *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;

            curr = curr->next->next;
        }

        // 2nd pass: for all the copies, set the random pointers
        curr = head;
        while (curr) {
            curr->next->random = curr->random ? curr->random->next : nullptr;

            curr = curr->next->next;
        }

        // 3rd pass: decouple all the copies
        RandomListNode dummy(0), *tail = &dummy;
        curr = head;
        while (curr) {
            tail->next = curr->next;
            tail = tail->next;
            curr->next = curr->next->next;

            curr = curr->next;
        }

        return dummy.next;
    }

    // n steps, O(n) space
    RandomListNode *copyRandomListHash(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> umap;
        RandomListNode dummy(0), *tail = &dummy;
        RandomListNode *curr = head;
        while (curr) {
            if (umap.find(curr) == umap.end()) {
                umap[curr] = new RandomListNode(curr->label);
            }

            if (curr->random && umap.find(curr->random) == umap.end()) {
                umap[curr->random] = new RandomListNode(curr->random->label);
            }

            tail->next = umap[curr];
            tail = tail->next;
            tail->random = umap[curr->random]; // umap[nullptr] will be value-initialized to nullptr
            curr = curr->next;
        }

        return dummy.next;
    }
};

#endif /* COPYLISTWITHRANDOMPOINTER_H_ */
