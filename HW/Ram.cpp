#include <iostream>
using namespace std;
#include "Ram.h"

void Ram::write(int address, char value) {//�ش� �ּҿ� ���� �Է��ϴ� �Լ�
	mem[address] = value;
}

char Ram::read(int address) { //�ش� �ּҿ� ����� �� �д� �Լ�
	return mem[address];
}

Ram::Ram() { //�����ڸ� �̿��Ͽ� �ɹ����� �ʱ�ȭ
	for (int i = 0; i < 100 * 1024; i++) { //mem�迭 0���� �ʱ�ȭ
		mem[i] = 0;
	}
	size = 100 * 1024;  //size 100*1024�� �ʱ�ȭ
}

Ram::~Ram() { //�Ҹ��ڰ� ����ϰ� �� ���ڿ�
	cout << "�޸� ���ŵ�" << endl;
}