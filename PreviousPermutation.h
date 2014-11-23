/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 23, 2014
 Problem:     Previous Permutation
 Difficulty:  5
 Source:      http://www.cplusplus.com/reference/algorithm/prev_permutation/
 Notes:
 Implement previous permutation, which rearranges numbers into the lexicographically previous smaller permutation of numbers.

 If such arrangement is not possible, it must rearrange it as the highest possible order (ie, sorted in descending order).

 The replacement must be in-place, do not allocate extra memory.

 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 ¡ú 3,2,1
 3,2,1 ¡ú 3,1,2
 4,1,5 ¡ú 1,4,5

 Solution:
 */

#ifndef PREVIOUSPERMUTATION_H_
#define PREVIOUSPERMUTATION_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;
using std::upper_bound;

#include <utility>
using std::swap;

#include <functional>
using std::less_equal;

class Solution {
public:
    void previousPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i-1] <= num[i])
            --i;
        reverse(num.begin() + i, num.end());
        if (i == 0) return;

        // linear search
        int j = i;
        while (num[j] >= num[i-1])
            ++j;
        swap(num[i-1], num[j]);
    }
};

#endif /* PREVIOUSPERMUTATION_H_ */
