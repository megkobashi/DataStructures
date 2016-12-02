void SelectionSort(int* A, int size) {
	for (int i = 0; i < size - 1; i++) {
		int smallest = i;
		for (int j = 1; j < size; j++) {
			if (A[smallest] > A[j]) {
				smallest = j;
			}
		}
		if (smallest != i) {
			int temp = A[smallest];
			A[smallest] = A[i];
			A[i] = temp;
		}
	}
}
