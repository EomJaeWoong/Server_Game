#include <iostream>

using namespace std;

int GenerateBinaryNumber(int);

int main() {
	int iInputNum;

	while (1) {
		cout << "Input Number : ";
		cin >> iInputNum;

		if (0 == iInputNum)
			return 0;

		GenerateBinaryNumber(iInputNum);
		cout << endl << endl;
	}
}

// 재귀함수로 계속 값을 나눈 후
int GenerateBinaryNumber(int iNum) {
	if (iNum <= 0)
		return 0;

	GenerateBinaryNumber(iNum / 2);
	printf("%d", iNum % 2);
}