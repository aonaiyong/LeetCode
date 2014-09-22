/*
 Author:     naiyong, aonaiyong@gmail.com
 Date:       Sep 20, 2014
 Problem:    Rotate An Array In Place
 Difficulty: 3
 Source:     Programming Pearls
 Notes:
 Rotate a one-dimensional array of n elements to the right by k steps.
 For instance, with n=7 and k=3, the array {a, b, c, d, e, f, g} is rotated to {e, f, g, a, b, c, d}.

 Solution:  Three reverse operations.
            O(n) time, O(1) space.
 */

#ifndef ROTATEANARRAYINPLACE_H_
#define ROTATEANARRAYINPLACE_H_

class Solution {
public:
	void rotate(int A[], int n, int k) {
		rotateToTheRight(A, n, k);
	}

	void rotateToTheRight(int A[], int n, int k) {
		k %= n;

		reverse(A, 0, n - 1);
		reverse(A, 0, k - 1);
		reverse(A, k, n - 1);
	}

	void rotateToTheLeft(int A[], int n, int k) {
		k %= n;

		reverse(A, 0, k - 1);
		reverse(A, k, n - 1);
		reverse(A, 0, n - 1);
	}

	void reverse(int A[], int low, int top) {
		while (low < top) {
			int temp = A[low];
			A[low] = A[top];
			A[top] = temp;

			++low;
			--top;
		}
	}
};


#endif /* ROTATEANARRAYINPLACE_H_ */
