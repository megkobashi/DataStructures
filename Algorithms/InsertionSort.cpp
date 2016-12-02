void InsertionSort(int* A, int size) {
	for (int j = 1; j < size; j++) {
		int i = j - 1;
		int key = A[j];
		while (0 <= j && A[i] > key) {
			A[i + 1] = A[i];
			j--;
		}
		A[i + 1] = key;
	}
}
