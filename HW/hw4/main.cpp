#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

int main() {
	//��ũ��, ������ ��ü ���� ����
	InkjetPrinter* inkP = new InkjetPrinter("Officejet V40", "HP", 0, 5, 10);
	LaserPrinter* laserP = new LaserPrinter("SCX-6x45", "�Ｚ����", 0, 3, 20);
	cout << endl;

	while (true) {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		int selectPrint, pages;
		cin >> selectPrint >> pages;
		if (selectPrint == 1) {
			inkP->printInkjet(pages);
		}
		else if (selectPrint == 2) {
			laserP->printLaser(pages);
		}
		else {
			cout << "1�� 2 �߿� �Է��Ͻʽÿ�." << endl<<endl;
			continue;
		}
		inkP->showInkjet();
		laserP->showLaser();
		
		while (true) {
			char choice;
			cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>>";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				cout << endl;
				break;
			}
			else if (choice == 'n' || choice == 'N') {
				delete inkP;
				delete laserP;
				return 0;
			}
			else {
				cout <<endl <<"y�� n �߿� �Է��Ͻʽÿ�." << endl;
			}
		}
	}
}