/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 17, 2014
 Problem:     Pascal's Triangle
 Difficulty:  2
 Source:      https://oj.leetcode.com/problems/pascals-triangle/
 Notes:
 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]
 Solution:    Pascal's triangle. http://en.wikipedia.org/wiki/Pascal's_triangle
 */

#ifndef PASCAL_STRIANGLE_H_
#define PASCAL_STRIANGLE_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle(numRows);
        for (int i = 0; i < numRows; ++i) {
            triangle[i].push_back(1);
            for (int j = 1; j < i; ++j)
                triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            if (i > 0)
                triangle[i].push_back(1);
        }
        return triangle;
    }
};

#endif /* PASCAL_STRIANGLE_H_ */
