#include <iostream>
#include <Windows.h>

#define P_HEIGHT 20
#define P_WIDTH 30

// �ϼ��� �׸��� Panel
char cPaintPanel[P_HEIGHT][P_WIDTH] = {
	{ ' ', ' ', ' ', 'N', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ' },
	{ ' ', 'N', ' ', 'N', 'N', 'N', 'N', 'N', ' ', ' ', ' ', ' ', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', 'N', 'N', ' ' },
	{ ' ', 'N', 'N', 'N', ' ', ' ', 'N', ' ', ' ', ' ', ' ', 'N', 'N', 'N', 'N', 'N', 'N', 'N', ' ', 'N', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ' },
	{ ' ', 'N', ' ', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', 'N', ' ', 'N', 'N', 'N', ' ', 'N', ' ', ' ', 'N', 'N', ' ', 'N', 'N', 'N', ' ', 'N', 'N', 'N' },
	{ ' ', 'N', 'N', 'N', ' ', ' ', 'N', ' ', 'N', ' ', 'N', ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', 'N', ' ', ' ' },
	{ ' ', 'N', ' ', 'N', 'N', 'N', 'N', ' ', 'N', ' ', 'N', ' ', 'N', 'N', ' ', ' ', ' ', 'N', ' ', ' ', 'N', 'N', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ' },
	{ ' ', 'N', 'N', 'N', ' ', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', ' ', ' ', ' ', 'N', ' ', 'N', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', 'N', 'N' },
	{ 'N', 'N', 'N', 'N', ' ', ' ', 'N', ' ', ' ', 'N', ' ', 'N', ' ', 'N', 'N', 'N', 'N', 'N', ' ', ' ', 'N', 'N', ' ', 'N', ' ', ' ', ' ', 'N', 'N', ' ' },
	{ ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', ' ', ' ' },
	{ ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', ' ', 'N', 'N', 'N' },
	{ ' ', ' ', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', ' ', ' ', ' ', 'N', ' ', 'N', 'N', 'N', 'N', 'N', ' ', 'N', 'N', 'N', ' ', ' ' },
	{ ' ', ' ', 'N', 'N', 'N', 'N', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', 'N', 'N', 'N', 'N', ' ', ' ', 'N', 'N', ' ', 'N', ' ', ' ', ' ', 'N', 'N', ' ' },
	{ ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ', 'N', 'N', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', 'N', 'N', ' ', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ' },
	{ 'N', 'N', ' ', 'N', 'N', ' ', 'N', ' ', ' ', ' ', 'N', 'N', 'N', 'N', ' ', ' ', ' ', 'N', ' ', 'N', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ' },
	{ 'N', 'N', ' ', 'N', 'N', ' ', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', ' ', ' ', 'N', ' ', 'N', 'N', 'N', ' ', 'N', ' ', ' ', 'N', 'N', ' ', ' ' },
	{ ' ', 'N', ' ', 'N', ' ', 'N', 'N', ' ', 'N', 'N', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ', 'N', 'N', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ' },
	{ ' ', 'N', 'N', 'N', ' ', 'N', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', 'N', 'N', ' ', 'N', ' ', ' ' },
	{ ' ', ' ', 'N', 'N', ' ', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ', 'N', 'N', 'N', ' ', ' ', ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ' },
	{ ' ', 'N', 'N', 'N', 'N', 'N', 'N', ' ', ' ', 'N', 'N', 'N', ' ', 'N', ' ', ' ', ' ', 'N', ' ', 'N', 'N', ' ', ' ', 'N', ' ', 'N', 'N', 'N', 'N', 'N' },
	{ 'N', 'N', ' ', 'N', ' ', ' ', 'N', ' ', 'N', 'N', 'N', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', 'N', ' ', ' ' }
};

void InitArray(int cInitChar);	// �׷��� Array �ʱ�ȭ
void DrawBuffer();
void PaintChar(int iHeight, int iWidth, char cChangeChar);

void main()
{
	while (1) {
		InitArray('Y');

		DrawBuffer();
		Sleep(3000);

		PaintChar(2, 3, 'Y');
		Sleep(3000);
	}
}

// Panel �ʱ�ȭ
void InitArray(int cInitChar) {
	system("cls");
	for (int y = 0; y < P_HEIGHT; y++) {
		for (int x = 0; x < P_WIDTH; x++) {
			if (cPaintPanel[y][x] == cInitChar)
				cPaintPanel[y][x] = 'N';
		}
	}
}

// Panel �׸���
void DrawBuffer() {
	// �ϳ��� ��ȸ�ϸ鼭 �����
	for (int y = 0; y < P_HEIGHT; y++) {
		for (int x = 0; x < P_WIDTH; x++)
			printf("%c ", cPaintPanel[y][x]);
		printf("\n");
	}
}

// Ư�� ���ǿ� ������ �ٸ� ���ڷ� �ٽ� �׸���
/* 1. ������ ����� �ʴ���, �ٲ� �������� �˻�, ����� �Լ� ����(return)
 * 2. Ÿ�� ������ ���, �ٲٰ� ��� �ٽ� �׸���
 * 3. ����� ������� ��, �Ʒ�, ����, ������ 4�������� �ٽ� �˻�
 */
void PaintChar(int iHeight, int iWidth, char cChangeChar) {
	// ���� ����� ��
	if ((iHeight < 0) || (iHeight >= P_HEIGHT) ||
		(iWidth < 0) || (iWidth >= P_WIDTH) || (cPaintPanel[iHeight][iWidth] != 'N'))
		return;

	// ���ǿ� ������ N => .�� �ٲ�
	else {
		cPaintPanel[iHeight][iWidth] = cChangeChar;

		system("cls");
		DrawBuffer();
	}

	PaintChar(iHeight - 1, iWidth, cChangeChar); // ��
	PaintChar(iHeight + 1, iWidth, cChangeChar); // �Ʒ�
	PaintChar(iHeight, iWidth - 1, cChangeChar); // ����
	PaintChar(iHeight, iWidth + 1, cChangeChar); // ������
}