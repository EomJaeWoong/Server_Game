#include <stdio.h>
#include <Windows.h>

#define LENGTH 10

void InsertSort(int arr[]);
void PrintArray(int arr[], int target);

void main()
{
	int Array[LENGTH] = { 3, 1, 22, 17, 19, 4, 11, 8, 21, 16 };

	InsertSort(Array);
}

void InsertSort(int arr[]) {
	for (int i = 1; i < LENGTH; i++) {
		int position = i;

		PrintArray(arr, i);

		// �ٲ� ������ ã��
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j])
				position = j;
		}

		// �迭 �б� �� �� ����
		int temp = arr[i];

		// �迭 �б�
		for (int k = i - 1; k >= position; k--) {
			arr[k + 1] = arr[k];
		}

		// ����
		arr[position] = temp;

		Sleep(2000);
	}

	PrintArray(arr, -1);
}

void PrintArray(int arr[], int target) {
	system("cls");

	// ��ȭ ����
	if (-1 != target) {
		printf("target:[], fixed: ()\n");

		for (int i = 0; i < LENGTH; i++) {
			if (i == 0)
				printf("( %d ", arr[i]);
			else if (i == target)
				printf(") [%d] ", arr[i]);
			else
				printf("%d ", arr[i]);
		}
	}

	// ���� �� ���
	else {
		printf("result : ");
		for (int i = 0; i < LENGTH; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}