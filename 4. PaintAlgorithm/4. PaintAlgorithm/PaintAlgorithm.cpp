#include <iostream>
#include <Windows.h>

#define P_HEIGHT 20
#define P_WIDTH 30

// 완성된 그림의 Panel
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

void InitArray(int cInitChar);	// 그려질 Array 초기화
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

// Panel 초기화
void InitArray(int cInitChar) {
	system("cls");
	for (int y = 0; y < P_HEIGHT; y++) {
		for (int x = 0; x < P_WIDTH; x++) {
			if (cPaintPanel[y][x] == cInitChar)
				cPaintPanel[y][x] = 'N';
		}
	}
}

// Panel 그리기
void DrawBuffer() {
	// 하나씩 순회하면서 찍어줌
	for (int y = 0; y < P_HEIGHT; y++) {
		for (int x = 0; x < P_WIDTH; x++)
			printf("%c ", cPaintPanel[y][x]);
		printf("\n");
	}
}

// 특정 조건에 맞으면 다른 문자로 다시 그리기
/* 1. 범위가 벗어나지 않는지, 바꿀 문자인지 검사, 벗어나면 함수 종료(return)
 * 2. 타깃 문자일 경우, 바꾸고 모두 다시 그리기
 * 3. 재귀적 방법으로 위, 아래, 왼쪽, 오른쪽 4방향으로 다시 검사
 */
void PaintChar(int iHeight, int iWidth, char cChangeChar) {
	// 범위 벗어나면 끝
	if ((iHeight < 0) || (iHeight >= P_HEIGHT) ||
		(iWidth < 0) || (iWidth >= P_WIDTH) || (cPaintPanel[iHeight][iWidth] != 'N'))
		return;

	// 조건에 맞으면 N => .로 바꿈
	else {
		cPaintPanel[iHeight][iWidth] = cChangeChar;

		system("cls");
		DrawBuffer();
	}

	PaintChar(iHeight - 1, iWidth, cChangeChar); // 위
	PaintChar(iHeight + 1, iWidth, cChangeChar); // 아래
	PaintChar(iHeight, iWidth - 1, cChangeChar); // 왼쪽
	PaintChar(iHeight, iWidth + 1, cChangeChar); // 오른쪽
}