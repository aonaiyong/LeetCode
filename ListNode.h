/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 22, 2014
 Problem:    List Node Class
 Difficulty:
 Source:
 Notes:

 Solution:
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif /* LISTNODE_H_ */
