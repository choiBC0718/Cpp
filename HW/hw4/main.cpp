#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

int main() {
	//잉크젯, 레이저 객체 동적 생성
	InkjetPrinter* inkP = new InkjetPrinter("Officejet V40", "HP", 0, 5, 10);
	LaserPrinter* laserP = new LaserPrinter("SCX-6x45", "삼성전자", 0, 3, 20);
	cout << endl;

	while (true) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		int selectPrint, pages;
		cin >> selectPrint >> pages;
		if (selectPrint == 1) {
			inkP->printInkjet(pages);
		}
		else if (selectPrint == 2) {
			laserP->printLaser(pages);
		}
		else {
			cout << "1과 2 중에 입력하십시오." << endl<<endl;
			continue;
		}
		inkP->showInkjet();
		laserP->showLaser();
		
		while (true) {
			char choice;
			cout << "계속 프린트 하시겠습니까?(y/n)>>";
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
				cout <<endl <<"y와 n 중에 입력하십시오." << endl;
			}
		}
	}
}