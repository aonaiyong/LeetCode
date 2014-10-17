/*
 Author:      naiyong, aonaiyong@gmail.com
 Date:        Oct 15, 2014
 Problem:     Heap Sort
 Difficulty:  3
 Source:      http://en.wikipedia.org/wiki/Heapsort
 Notes:
 Sort an array using heapsort.

 Solution:    http://en.wikipedia.org/wiki/Heapsort
              http://www.sorting-algorithms.com/heap-sort

              Time:   O(nlogn)
              Space:  O(1)

              Property:  Not stable.
                         Not really adaptive.

              Because of the O(nlogn) upper bound on heapsort's running time and constant upper bound
              on its auxiliary storage, embedded systems with real-time constraints or systems concerned
              with security often use heapsort.
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <utility>
using std::swap;

#define PARENT(i)  (((i)-1)/2)
#define LEFT(i)    (2*(i)+1)
#define RIGHT(i)   (2*(i)+2)

class Solution {
public:
    void heapSort(int A[], int n) {
        buildMaxHeap(A, n);
        for (int i = n-1; i >= 1; --i) {
            swap(A[0], A[i]);
            maxHeapify(A, i, 0);
        }
    }

    void buildMaxHeap(int A[], int n) {
        for (int i = PARENT(n-1); i >= 0; --i)
            maxHeapify(A, n, i);
    }

    void maxHeapify(int A[], int n, int i) {
        int l = LEFT(i), r = RIGHT(i);
        int largest = i;
        if (l < n && A[l] > A[largest])
            largest = l;
        if (r < n && A[r] > A[largest])
            largest = r;
        if (largest != i) {
            swap(A[i], A[largest]);
            maxHeapify(A, n, largest);
        }
    }

    void maxHeapifyIterative(int A[], int n, int i) {
        while (LEFT(i) < n) {
            int l = LEFT(i), r = RIGHT(i);
            int largest = i;
            if (A[l] > A[largest])
                largest = l;
            if (r < n && A[r] > A[largest])
                largest = r;
            if (largest != i) {
                swap(A[i], A[largest]);
                i = largest;
            }
            else
                return;
        }
    }
};

#endif /* HEAPSORT_H_ */
