/*

 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 14, 2014
 Problem:     Bubble Sort
 Difficulty:  2
 Source:      http://en.wikipedia.org/wiki/Bubble_sort
 Notes:
 Sort an array using bubble sort.

 Solution:    http://en.wikipedia.org/wiki/Bubble_sort
              http://www.sorting-algorithms.com/bubble-sort

              Loop Invariant:    |         |    <    |       <       |
                                  0     i-1 i         n             N

                                 |         |           <             |
                                  0         n                       N
                  A[n], ..., A[N] are in their final, sorted positions (N = A.size - 1).
                  The last swap of current pass happened at index i.

              Termination:       |                  <                |
                                  n                                 N

              Worst-case time:      O(n^2) comparisons/swaps.
              Best-case time:       O(n) comparisons, O(1) swaps.
              Average-case time:    O(n^2) comparisons/swaps.
              Worst-case time:      O(1).

              Property:    Stable & In-place & Adaptive.
 */

#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <utility>
using std::swap;

class Solution {
public:
    void bubbleSortArray(int A[], int n) {
    	while (n > 0) {
    	    int newn = 0;
            for (int i = 1; i < n; ++i) {
            	if (A[i-1] > A[i]) {
            	    swap(A[i-1], A[i]);
            	    newn = i;
                }
            }
            n = newn;
    	}
    }
};

#endif /* BUBBLESORT_H_ */
