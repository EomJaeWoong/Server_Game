#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int iInputByte;
	int iInputValue;

	unsigned int uiData = 0;

	while (1){
		// input 
		cout << "��ġ(1~4) : " ;
		cin >> iInputByte;

		cout << "��(0~255) : ";
		cin >> iInputValue;

		// ���� üũ
		if (iInputValue < 0 || iInputValue > 255) {
			cout << "���� ������ �ʰ��Ͽ����ϴ�.\n" << endl;
			continue;
		}


		switch (iInputByte) {
		case 1 :
		case 2 :
		case 3 :
		case 4 :
			// �ش� ����Ʈ �ڸ��� �����
			// 1. ��ġ��ŭ 0xff�� 8bit ������ shift �ؼ� NOT ����
			//		ex) 2���̸� 0xffff00ff
			// 2. 1�� ���� AND���� -> �ش� ����Ʈ �ڸ��� �ʱ�ȭ
			uiData = uiData & ~(0xff << (iInputByte - 1) * 8);

			// �ش� ����Ʈ �ڸ��� �� ����
			// 1. ��ġ��ŭ ���� 8bit ������ shift
			//		ex) 2�� ��ġ, ���� fe�� 0x0000fe00
			// 2. 1�� ���� or ����
			uiData = uiData | (iInputValue << (iInputByte - 1) * 8);

			break;

		// ���� üũ
		default :
			cout << "�ùٸ� ��ġ�� �ƴմϴ�.\n" << endl;
			continue;
		}

		int iSizeData = sizeof(uiData);

		// �� �ڸ��� ����Ʈ �� ���
		for (int iCnt = 0; iCnt < iSizeData; iCnt++)
		{
			int uiTemp = uiData & (0xff << (iSizeData - iCnt - 1) * 8);
			uiTemp = uiTemp >> (iSizeData - iCnt - 1) * 8;
			cout << iCnt << "��°�� ����Ʈ �� : " << hex << setw(2) << setfill('0') << uiTemp  << endl;
		}

		cout << endl;
		cout << "��ü ����Ʈ �� : " << hex << setfill('0') << setw(8) << uiData << endl;
		cout << endl;
	}

	return 0;
}