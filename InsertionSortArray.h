/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 13, 2014
 Problem:     Insertion Sort Array
 Difficulty:  1
 Source:      http://en.wikipedia.org/wiki/Insertion_sort
 Notes:
 Sort an array using insertion sort.

 Solution:    http://en.wikipedia.org/wiki/Insertion_sort

              Loop invariant:    |     <      |      ?       |
                                  0        i-1 i          n-1

              Initialization:    |<|            ?            |
                                  0 i                     n-1

              Termination:       |              <            |
                                  0                       n-1  i

              Worst-case time:    O(n^2) comparisons/swaps
              Best-case time:     O(n) comparisons, O(1) swaps
              Average-case time:  O(n^2) comparisons/swaps
              Worst-case space:   O(1)
 */

#ifndef INSERTIONSORTARRAY_H_
#define INSERTIONSORTARRAY_H_

void insertionSortArray(int A[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			--j;
		}
		A[j+1] = key;
	}
}

#endif /* INSERTIONSORTARRAY_H_ */
