#include <stdio.h>
#include <cstdlib>
//int arr[];
int *arr = nullptr;
void swap(int*, int*);
void heapify(int pos, int n) {
	while (2 * pos + 1 < n) {

		int t = 2 * pos + 1;	//Изначально выбираем левого ребенка
		if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t]) //Проверяем детей кто больше того выбираем
		{
			t = 2 * pos + 2;
		}
		if (arr[pos] < arr[t]) {
			swap(&arr[pos], &arr[t]);
			pos = t;
		}
		else break;

	}
}

void heap_make(int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		heapify(i, n);
	}
}
void heap_sort(int n)
{
	heap_make(n);
	while (n>0)
	{
		swap(&arr[0], &arr[n - 1]);
		n--;
		heapify(0, n);
	}
}

void swap(int* a, int*b )
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n;
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));

	
	if (arr == NULL)
	{
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d",arr+i);
	}
	heap_sort(n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);;
	}
	free(arr);
	return 0;
}