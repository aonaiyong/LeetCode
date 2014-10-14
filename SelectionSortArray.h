/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 13, 2014
 Problem:     Selection Sort Array
 Difficulty:  2
 Source:      http://en.wikipedia.org/wiki/Selection_sort
 Notes:
 Sort an array using selection sort.

 Solution:   http://en.wikipedia.org/wiki/Selection_sort
             http://www.sorting-algorithms.com/selection-sort

             Loop Invariant:     |    <     |                |
                                  0          i     iMin   n-1
                A[0], ..., A[i-1] are in their final, sorted positions

             Initialization:     |                           |
                                  i                       n-1

             Termination:        |                           |
                                  0                         i


             Worst-case time:    O(n^2) comparisons, O(n) swaps
             Best-case time:     O(n^2) comparisons, O(1) swaps
             Average-case time:  O(n^2) comparisons, O(n) swaps

             Property:    Not stable.
                          Not adaptive.
                          In-place.

             Selection sort has the property of minimizing the number of swaps.
             In application where the cost of swapping items is high, selection sort
             very well may be the algorithm of choice.

 */

#ifndef SELECTIONSORTARRAY_H_
#define SELECTIONSORTARRAY_H_

#include <utility>
using std::swap;

class Solution {
public:
	void selectionSortArray(int A[], int n) {
		for (int i = 0; i < n-1; ++i) {
			int iMin = i;
			for (int j = i + 1; j < n; ++j) {
				if (A[j] < A[iMin])
				    iMin = j;
			}

			if (iMin != i)
			    swap(A[i], A[iMin]);
		}
	}
};

#endif /* SELECTIONSORTARRAY_H_ */
