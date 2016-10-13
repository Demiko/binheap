#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void
min_heapify(int *arr, int len, int i) {
	int left, right, min, tmp;

	left = i * 2 + 1;
	right = i * 2 + 2;
	min = i;

	if (left < len && arr[left] < arr[min])
		min = left;
	if (right < len && arr[right] < arr[min])
		min = right;

	if (min != i) {
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;

		min_heapify(arr, len, min);
	}
}

int
main(int argc, char **argv) {
	int len, tmp, i;
	int *arr;

	tmp = scanf("%d", &len);
	if (tmp != 1) {
		perror("Error reading length");
		exit(errno);
	}

	if (len < 1) {
		errno = EINVAL;
		perror("Length must be greater than 0\n");
		exit(errno);
	}

	arr = malloc(sizeof(int) * len);
	if (arr == NULL) {
		perror("Can't allocate memory for array\n");
		exit(errno);
	}

	for (i = 0; i < len; ++i) {
		tmp = scanf("%d", arr + i);
		if (tmp != 1) {
			perror("Error reading element");
			exit(errno);
		}
	}

	for (i = len / 2 - 1; i >= 0; --i)
		min_heapify(arr, len, i);

	while (len--) {
		printf("%d\n", arr[0]);
		arr[0] = arr[len];
		min_heapify(arr, len, 0);
	}
}
