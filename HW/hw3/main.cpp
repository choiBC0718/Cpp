#include <iostream>
using namespace std;
#include "Dept.h"

int countPass(Dept dept) {	//60�� �̻����� ����ϴ� �л� �� ����
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) {
			count++;
		}
	}
	return count;
}

int main() {
	Dept com(10);			//size=10�� ��ü com
	com.read();				//10�� �л����� ������ Ű����κ��� �о� socres�迭�� ����
	int n = countPass(com);
	cout << "60�� �̻��� " << n << "��"<<endl;
}