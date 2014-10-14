/*

 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 14, 2014
 Problem:     Bubble Sort Array
 Difficulty:  2
 Source:      http://en.wikipedia.org/wiki/Bubble_sort
 Notes:
 Sort an array using bubble sort.

 Solution:    http://en.wikipedia.org/wiki/Bubble_sort

              Loop Invariant:    |         |    <    |       <       |
                                  0     i-1 i         n             N

                                 |         |           <             |
                                  0         n                       N
                  A[n], ..., A[N] are in their final, sorted positions (N = A.size - 1).
                  the last swap of current pass happened at index i.

              Termination:       |                  <                |
                                  n                                 N

              Worst-case time:      O(n^2) comparisons/swaps.
              Best-case time:       O(n) comparisons, O(1) swaps.
              Average-case time:    O(n^2) comparisons/swaps.
              Worst-case time:      O(1).

              In computer graphics, it is popular for its capability to detect a very small error
              (like swap of just two elements) in almost-sorted arrays, and fix it with just linear complexity (2n).
 */

#ifndef BUBBLESORTARRAY_H_
#define BUBBLESORTARRAY_H_

#include <utility>
using std::swap;

void bubbleSortArray(int A[], int n) {
	while (n) {
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

#endif /* BUBBLESORTARRAY_H_ */
