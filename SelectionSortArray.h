/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 13, 2014
 Problem:     Selection Sort Array
 Difficulty:  2
 Source:      http://en.wikipedia.org/wiki/Selection_sort
 Notes:
 Sort an array using selection sort.

 Solution:   http://en.wikipedia.org/wiki/Selection_sort
 */

#ifndef SELECTIONSORTARRAY_H_
#define SELECTIONSORTARRAY_H_

#include <utility>
using std::swap;

void selectionSortArray(int A[], int n) {
	for (int i = 0; i < n; ++i) {
		int iMin = i;
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[iMin])
			    iMin = j;
		}

		if (iMin != i)
		    swap(A[i], A[iMin]);
	}
}

#endif /* SELECTIONSORTARRAY_H_ */
