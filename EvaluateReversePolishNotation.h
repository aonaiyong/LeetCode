/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 19, 2014
 Problem:     Evaluate Reverse Polish Notation
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 Notes:
  Evaluate the value of an arithmetic expression in Reverse Polish Notation.

  Valid operators are +, -, *, /. Each operand may be an integer or another expression.

  Some examples:

    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 Solution:    Reverse Polish notation.
              http://en.wikipedia.org/wiki/Reverse_Polish_notation
 */

#ifndef EVALUATEREVERSEPOLISHNOTATION_H_
#define EVALUATEREVERSEPOLISHNOTATION_H_

#include <vector>
using std::vector;

#include <string>
using std::string; using std::stoi;

#include <stack>
using std::stack;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            const string &s = tokens[i];
            if (!isOperator(s))
                stk.push(stoi(s));
            else {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                if (s == "+")
                    stk.push(b + a);
                else if (s == "-" )
                    stk.push(b - a);
                else if (s == "*")
                    stk.push(b * a);
                else if (s == "/")
                    stk.push(b / a);
            }
        }
        return stk.top();
    }

    bool isOperator(const string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};

#endif /* EVALUATEREVERSEPOLISHNOTATION_H_ */
