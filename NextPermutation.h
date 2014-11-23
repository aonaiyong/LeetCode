/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Nov 23, 2014
 Problem:     Next Permutation
 Difficulty:  5
 Source:      https://oj.leetcode.com/problems/next-permutation/
 Notes:
  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

 The replacement must be in-place, do not allocate extra memory.

 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 ¡ú 1,3,2
 3,2,1 ¡ú 1,2,3
 1,1,5 ¡ú 1,5,1

 Solution:    http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
              1. Starting from the last element, traverse backward to find the largest index i such that num[i] > num[i-1];
              2. Reverse num[i...n-1];
              3. If i equals 0, then we're done;
              4. Otherwise, find the smallest index j no less than k such that num[j] > num[i-1];
              5. Swap num[i-1] and num[j].

              Time: O(n), Space: O(1).

 */

#ifndef NEXTPERMUTATION_H_
#define NEXTPERMUTATION_H_

#include <vector>
using std::vector;

#include <algorithm>
using std::reverse;
using std::upper_bound;

#include <utility>
using std::swap;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // nextPermutation_1(num);
        nextPermutation_2(num);
    }

    bool nextPermutation_1(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i-1] >= num[i])
            --i;
        reverse(num.begin() + i, num.end());
        if (i == 0) return false;

        // linear search
        int j = i;
        while (num[j] <= num[i-1])
            ++j;
        swap(num[i-1], num[j]);
        return true;
    }

    bool nextPermutation_2(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i-1] >= num[i])
            --i;
        reverse(num.begin() + i, num.end());
        if (i == 0) return false;

        // binary search
        int j = upper_bound(num.begin() + i, num.end(), num[i-1]) - num.begin();
        swap(num[i-1], num[j]);
        return true;
    }
};

#endif /* NEXTPERMUTATION_H_ */
