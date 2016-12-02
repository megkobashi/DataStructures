void BubbleSort(int* A, int size) {
	bool didswap = true;
	while (didswap) {
		for (int i = 0; i < size - 1; i++) {
			didswap = false;
			if (A[i] > A[i + 1]) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				didswap = true;
			}
		}
	}
}
