#include <iostream>
#include <vector>
using namespace std;
#include "Shape.h"

int main() {
	vector<Shape*> v;
	vector<Shape*>::iterator it;
	cout << "그래픽 에디터입니다." << endl;

	while (true) {
		int choiceMenu = UI::menu();
		Shape* jobShape = NULL;

		if (choiceMenu == 1) {				//도형 삽입
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
				cout << endl << "잘못된 값 입력" << endl;
			}
			v.push_back(jobShape);
		}

		else if (choiceMenu == 2) {			//도형 삭제
			it = v.begin();
			if (v.size()<=0) {
				cout << "삭제할 도형이 없습니다." << endl << endl;
			}
			else {
				int choiceIndex = UI::delShape();
				if (choiceIndex > v.size()) {
					cout << "인덱스 초과 오류" << endl << endl;
					continue;
				}
				else {
					int i = 0;
					for (i; i < choiceIndex; i++) {
						it++;
					}
					jobShape = *it;
					cout << "삭제 완료 ";
					jobShape->paint();
					cout << endl;
					delete jobShape;
					it = v.erase(it);
				}
			}
		}

		else if (choiceMenu == 3) {			//도형 보기
			if (v.size() <= 0) {
				cout << "vector 컨테이너에 들어있는 도형이 없습니다." << endl<<endl;
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					cout << i << ": ";
					v[i]->paint();
				}
				cout << endl;
			}
			/*  iterator 사용하여 도형 보는 방법
			if (v.size() <= 0) {
				cout << "vector 컨테이너에 들어있는 도형이 없습니다." << endl<<endl;
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

		else if (choiceMenu == 4) {			//종료
			cout <<endl<< "프로그램을 종료합니다." << endl;
			return 0;
		}

		else {
			cout << endl << "잘못된 입력입니다." << endl;
		}
	}
}