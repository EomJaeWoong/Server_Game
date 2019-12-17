#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int iInputByte;
	int iInputValue;

	unsigned int uiData = 0;

	while (1){
		// input 
		cout << "위치(1~4) : " ;
		cin >> iInputByte;

		cout << "값(0~255) : ";
		cin >> iInputValue;

		// 범위 체크
		if (iInputValue < 0 || iInputValue > 255) {
			cout << "값의 범위를 초과하였습니다.\n" << endl;
			continue;
		}


		switch (iInputByte) {
		case 1 :
		case 2 :
		case 3 :
		case 4 :
			// 해당 바이트 자리만 비워줌
			// 1. 위치만큼 0xff를 8bit 단위로 shift 해서 NOT 연산
			//		ex) 2번이면 0xffff00ff
			// 2. 1의 값을 AND연산 -> 해당 바이트 자리만 초기화
			uiData = uiData & ~(0xff << (iInputByte - 1) * 8);

			// 해당 바이트 자리에 값 삽입
			// 1. 위치만큼 값을 8bit 단위로 shift
			//		ex) 2번 위치, 값이 fe면 0x0000fe00
			// 2. 1의 값을 or 연산
			uiData = uiData | (iInputValue << (iInputByte - 1) * 8);

			break;

		// 범위 체크
		default :
			cout << "올바른 위치가 아닙니다.\n" << endl;
			continue;
		}

		int iSizeData = sizeof(uiData);

		// 각 자리의 바이트 값 출력
		for (int iCnt = 0; iCnt < iSizeData; iCnt++)
		{
			int uiTemp = uiData & (0xff << (iSizeData - iCnt - 1) * 8);
			uiTemp = uiTemp >> (iSizeData - iCnt - 1) * 8;
			cout << iCnt << "번째의 바이트 값 : " << hex << setw(2) << setfill('0') << uiTemp  << endl;
		}

		cout << endl;
		cout << "전체 바이트 값 : " << hex << setfill('0') << setw(8) << uiData << endl;
		cout << endl;
	}

	return 0;
}