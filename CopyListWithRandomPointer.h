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
        RandomListNode *node = head;
        while (node) {
            RandomListNode *copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;

            node = copy->next;
        }

        // 2nd pass: for all the copies, set the random pointers
        node = head;
        while (node) {
            RandomListNode *copy = node->next;
            copy->random = node->random ? node->random->next : nullptr;

            node = copy->next;
        }

        // 3rd pass: decouple all the copies
        node = head;
        RandomListNode dummy(0), *tail = &dummy;
        while (node) {
            tail = tail->next = node->next;
            node = node->next = tail->next;
        }
        return dummy.next;
    }

    // n steps, O(n) space
    RandomListNode *copyRandomListHash(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> umap;
        RandomListNode dummy(0), *tail = &dummy;
        while (head) {
            if (!umap.count(head))
                umap[head] = new RandomListNode(head->label);
            if (head->random && !umap.count(head->random))
                umap[head->random] = new RandomListNode(head->random->label);
            tail = tail->next = umap[head];
            tail->random = umap[head->random];

            head = head->next;
        }

        return dummy.next;
    }
};

#endif /* COPYLISTWITHRANDOMPOINTER_H_ */
