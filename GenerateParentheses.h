/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Oct 2, 2014
 Problem:    Generate Parentheses
 Difficulty: 3
 Source:     https://oj.leetcode.com/problems/generate-parentheses/
 Notes:
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"

 Solution:   Binary Tree Depth-first traversal.
             Rule: We can place '(' when '(' is available.
                   We can place ')' only when there're more ')' available than '('.
 */

#ifndef GENERATEPARENTHESES_H_
#define GENERATEPARENTHESES_H_

#include <vector>
using std::vector;

#include <string>
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        string parens;
        generateParenthesis(combinations, parens, n, n);

        return combinations;
    }

    void generateParenthesis(vector<string> &combinations, string parens, int left, int right) {
        if (!left && !right) {
            combinations.push_back(parens);
            return;
        }

        if (left > 0) generateParenthesis(combinations, parens + '(', left-1, right);
        if (right > left) generateParenthesis(combinations, parens + ')', left, right-1);
    }
};

#endif /* GENERATEPARENTHESES_H_ */
