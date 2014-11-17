/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 17, 2014
 Problem:     Pascal's Triangle II
 Difficulty:  2
 Source:      https://github.com/leetcoders/LeetCode/blob/master/Pascal'sTriangleII.h
 Notes:
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?

 Solution:    Pascal's triangle. http://en.wikipedia.org/wiki/Pascal's_triangle
              Calculate from back to forth.
 */

#ifndef PASCAL_STRIANGLEII_H_
#define PASCAL_STRIANGLEII_H_

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j)
                row[j] += row[j-1];
        }
        return row;
    }
};

#endif /* PASCAL_STRIANGLEII_H_ */
