#include <iostream>
using namespace std;

void Merge (int* A, int begin, int middle, int end) {
	int B[end - begin + 1];
	int x = 0;
	int y = 0;
	for (int i = 0; i < end - begin + 1; i++) {
		if (begin + x > middle) {
			std::copy(A + middle + 1 + y, A + end + 1, B + i);
			break;
		} else if (middle + 1 + y > end) {
			std::copy(A + begin + x, A + middle + 1, B + i);
			break;
		} else if (A[begin + x] < A[middle + 1 + y]) {
			B[i] = A[begin + x];
			x++;
		} else {
			B[i] = A[middle + 1 + y];
			y++;
		}
	}
	std::copy(B + 0, B + end - begin + 1, A + begin);
}

void MergeSort(int* A, int begin, int end) {
	if (begin < end) {
		int middle = (begin + end) / 2;
		MergeSort(A, begin, middle);
		MergeSort(A, middle + 1, end);
		Merge(A, begin, middle, end);
	}
}

void printArray(int* A, int size) {
	for (int i = 0; i < size; i++) {
		if (i != size - 1) {
			cout << A[i] << ", ";
		} else {
			cout << A[i] << endl;
		}
	}
}

int main() {
	int A[8] = {8, 3, 4, 5, 6, 7, 8, 9};
	MergeSort(A, 0, 7);
//	printArray(A, 7);
	return 0;
}
