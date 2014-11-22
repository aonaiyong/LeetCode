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

 Solution:   DFS.
             Rule: We can place '(' when it's available.
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
        // generateParenthesis_1(n, n, parens, combinations);
        generateParenthesis_2(n, n, "", combinations);
        return combinations;
    }

    void generateParenthesis_1(int left, int right, string &parens, vector<string> &combinations) {
        if (!right) {
            combinations.push_back(parens);
            return;
        }

        if (left) {
            parens.push_back('(');
            generateParenthesis_1(left - 1, right, parens, combinations);
            parens.pop_back();
        }

        if (right > left) {
            parens.push_back(')');
            generateParenthesis_1(left, right - 1, parens, combinations);
            parens.pop_back();
        }
    }

    void generateParenthesis_2(int left, int right, string parens, vector<string> & combinations) {
        if (!right) {
            combinations.push_back(parens);
            return;
        }

        if (left) generateParenthesis_2(left - 1, right, parens + '(', combinations);
        if (right > left) generateParenthesis_2(left, right - 1, parens + ')', combinations);
    }
};

#endif /* GENERATEPARENTHESES_H_ */
