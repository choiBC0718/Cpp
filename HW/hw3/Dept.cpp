#include <iostream>
using namespace std;
#include "Dept.h"

Dept::Dept(int size) {		//size�� �Ű������� �޴� ������
	this->size = size;
	scores = new int[size];
}

Dept::Dept(const Dept& dept) {	//���� ������
	this->size = dept.size;
	scores = new int[dept.size];//���� ���縦 ���� �ʱ� ���� �޸� ���� Ȯ��
	for (int i = 0; i < dept.size; i++) { //�Ҵ��� �޸𸮿� �� �����Ͽ� �ֱ�
		scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {	//�Ҹ���
	if (scores) {
		delete[] scores;		//�������� �Ҵ� ���� �޸� ��ȯ
	}
}

int Dept::getSize() {
	return size;
}

void Dept::read() {				//�Է��� ������ scores �迭�� �ݺ����� ���� ����
	cout << size << "�� ���� �Է�>> " ;
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {  //���� �����ڸ� ���� ������ ��ü�� scores �迭�� ���� ��������� ��. �� ����� ����
	if (scores[index] >= 60) {
		return true;
	}
	else
		return false;
}