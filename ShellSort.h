/*

 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 16, 2014
 Problem:     Shell Sort
 Difficulty:  2
 Source:      http://en.wikipedia.org/wiki/Shellsort
 Notes:
 Sort an array using shell sort.

 Solution:    http://en.wikipedia.org/wiki/Shellsort
              http://www.sorting-algorithms.com/shell-sort

 */

#ifndef SHELLSORT_H_
#define SHELLSORT_H_

class Solution {
	void shellSort(int A[], int n) {
		int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1};
		for (auto gap : gaps)
			for (int i = gap; i < n; ++i) {
				int key = A[i];
				int j = i - gap;
				while (j >= 0 && A[j] > key) {
					A[j + gap] = A[j];
					j -= gap;
				}
				A[j + gap] = key;
			}
	}
};


#endif /* SHELLSORT_H_ */
