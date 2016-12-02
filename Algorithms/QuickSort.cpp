void Partition(int* A, int begin, int end) {
	int pivot = A[begin];
	int i = begin + 1;
	for (int j = begin + 1; j < end; i++) {
		if (A[j] < pivot) {
			int temp = A[j];
			A[j] = A[i];
			A[i] = temp;
			i++;
		}
	}
	A[begin] = A[i];
	A[i] = pivot;
}

void QuickSort(int* A, int begin, int end) {
	if (begin < end) {
		int x = Partition(A, begin, end);
		QuickSort(A, begin, x);
		QuickSort(A, x + 1, end);
	}
}


