/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 16, 2014
 Problem:     Valid Parentheses
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/valid-parentheses/
 Notes:
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 Solution:    stack.
 */

#ifndef VALIDPARENTHESES_H_
#define VALIDPARENTHESES_H_

#include <string>
using std::string;

#include <unordered_map>
using std::unordered_map;

#include <stack>
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap{ {'(', ')'}, {'{', '}'}, {'[', ']'} };
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty() || c != umap[stk.top()])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

#endif /* VALIDPARENTHESES_H_ */
