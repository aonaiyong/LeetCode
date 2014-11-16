/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 16, 2014
 Problem:     Min Stack
 Difficulty:  3
 Source:      https://oj.leetcode.com/problems/min-stack/
 Notes:
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.

 Solution:    Two stacks.
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_

#include <stack>
using std::stack;

class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if (minStk.empty() || x <= minStk.top())
            minStk.push(x);
    }

    void pop() {
        int x = stk.top();
        stk.pop();
        if (x == minStk.top())
            minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
private:
    stack<int> stk;
    stack<int> minStk;
};

#endif /* MINSTACK_H_ */
