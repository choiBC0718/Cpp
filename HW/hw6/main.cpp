#include <iostream>
#include <vector>
using namespace std;
#include "Shape.h"

int main() {
	vector<Shape*> v;
	vector<Shape*>::iterator it;
	cout << "�׷��� �������Դϴ�." << endl;

	while (true) {
		int choiceMenu = UI::menu();
		Shape* jobShape = NULL;

		if (choiceMenu == 1) {				//���� ����
			int choiceShape = UI::selectShape();

			if (choiceShape == 1) {
				cout << "Insert Line" << endl << endl;
				jobShape = new Line;
			}
			else if (choiceShape == 2) {
				cout << "Insert Circle" << endl << endl;
				jobShape = new Circle;
			}
			else if (choiceShape == 3) {
				cout << "Insert Rectangle" << endl << endl;
				jobShape = new Rect;
			}
			else {
				cout << endl << "�߸��� �� �Է�" << endl;
			}
			v.push_back(jobShape);
		}

		else if (choiceMenu == 2) {			//���� ����
			it = v.begin();
			if (v.size()<=0) {
				cout << "������ ������ �����ϴ�." << endl << endl;
			}
			else {
				int choiceIndex = UI::delShape();
				if (choiceIndex > v.size()) {
					cout << "�ε��� �ʰ� ����" << endl << endl;
					continue;
				}
				else {
					int i = 0;
					for (i; i < choiceIndex; i++) {
						it++;
					}
					jobShape = *it;
					cout << "���� �Ϸ� ";
					jobShape->paint();
					cout << endl;
					delete jobShape;
					it = v.erase(it);
				}
			}
		}

		else if (choiceMenu == 3) {			//���� ����
			if (v.size() <= 0) {
				cout << "vector �����̳ʿ� ����ִ� ������ �����ϴ�." << endl<<endl;
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					cout << i << ": ";
					v[i]->paint();
				}
				cout << endl;
			}
			/*  iterator ����Ͽ� ���� ���� ���
			if (v.size() <= 0) {
				cout << "vector �����̳ʿ� ����ִ� ������ �����ϴ�." << endl<<endl;
			}
			else {
				int i = 0;
				for (it = v.begin(); it != v.end(); it++) {
					jobShape = *it;
					cout << i << ": ";
					jobShape->paint();
					i++;
				}
				cout << endl;
			}
			*/
		}

		else if (choiceMenu == 4) {			//����
			cout <<endl<< "���α׷��� �����մϴ�." << endl;
			return 0;
		}

		else {
			cout << endl << "�߸��� �Է��Դϴ�." << endl;
		}
	}
}