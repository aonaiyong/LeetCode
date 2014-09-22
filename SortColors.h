/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 21, 2014
 Problem:    Sort Colors (Dutch national flag problem)
 Difficulty: 4
 Source:     https://oj.leetcode.com/problems/sort-colors/
 Notes:
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 Note that you are not suppose to use the library's sort function for this problem.

 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

 Could you come up with an one-pass algorithm using only constant space?

 Solution:  1. Three way partition. http://en.wikipedia.org/wiki/Dutch_national_flag_problem

               Loop invariant:  0 0 0 0 0 1 1 1 1 1 ? ? ? ? 2 2 2 2
                                |       |           |       |     |
                                0       i           j       k   n-1
            2. Counting sort.
 */

#ifndef SORTCOLORS_H_
#define SORTCOLORS_H_

#include <vector>
using std::vector;

#include <utility>
using std::swap;

class Solution {
public:
    void sortColors(int A[], int n) {
        threeWayPartition(A, n);
        // countingSort(A, n);
    }

    void threeWayPartition(int A[], int n) {
        const int red = 0, white = 1, blue = 2;
        int i = -1, j = 0, k = n;
        while (j < k) {
            switch(A[j]) {
            case red:
                swap(A[++i], A[j++]);
                break;
            case white:
                ++j;
                break;
            case blue:
                swap(A[j], A[--k]);
                break;
            default:
                break;
            }
        }
    }

    void countingSort(int A[], int n) {
        vector<int> B(n);
        int C[3] = {0};

        // count
        for (int i = 0; i < n; ++i) {
            ++C[A[i]];
        }

        // prefix sum
        for (int i = 1; i < 3; ++i) {
            C[i] += C[i-1];
        }

        // stable sort (back-to-forth)
        for (int i = n - 1; i >= 0; --i) {
            --C[A[i]];
            B[C[A[i]]] = A[i];
        }

        // copy back
        for (int i = 0; i < n; ++i) {
            A[i] = B[i];
        }
    }

};


#endif /* SORTCOLORS_H_ */
