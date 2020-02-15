#include <stdio.h>
#include <Windows.h>

#define LENGTH 10

void BubbleSort(int[]);

void main()
{
	int Array[LENGTH] = { 10, 25, 13, 2, 11, 4, 7, 5, 9, 12 };

	BubbleSort(Array);
}

// Bubble Sort
void BubbleSort(int arr[])
{
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH - i - 1; j++) {
			system("cls");
			printf("() => fixed, [] => target\n");

			// 비교 : []
			// 정렬 완료 : ()
			for (int k = 0; k < LENGTH; k++) {
				if ((k == j) || (k == j + 1))
					printf("[%d] ", arr[k]);
				else if (k >= (LENGTH - i))
					printf("(%d) ", arr[k]);
				else
					printf("%d ", arr[k]);
			}
			Sleep(500);

			// 교환
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// 결과
	system("cls");
	printf("Result : ");
	for (int i = 0; i < LENGTH; i++)
		printf("%d ", arr[i]);
	printf("\n");
}