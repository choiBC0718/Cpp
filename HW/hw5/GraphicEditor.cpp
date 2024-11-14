#include <iostream>
#include "GraphicEditor.h"
using namespace std;

//Shape 클래스 멤버 구현
void Shape::paint() {
	draw();
}
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}

//각 draw함수 구현
void Line::draw() {
	cout << "Line" << endl;
}
void Circle::draw() {
	cout << "Circle" << endl;
}
void Rect::draw() {
	cout << "Rectangle" << endl;
}

//GraphicEditor 클래스 멤버 구현
GraphicEditor::GraphicEditor() {
	pStart = NULL;
	pLast = NULL;
	cout << "그래픽 에디터입니다." << endl;
}
GraphicEditor::~GraphicEditor() {
	Shape* p = pStart;
	while (p != NULL) {
		Shape* q = p->getNext();
		delete p;
		p = q;
	}
}
void GraphicEditor::insertShape() {
	int choiceShape = UI::selectShape();
	Shape* newShape = NULL;

	switch (choiceShape) {
	case 1:
		cout << "선 삽입" << endl << endl;
		newShape = new Line();
		break;
	case 2:
		cout << "원 삽입" << endl << endl;
		newShape = new Circle();
		break;
	case 3:
		cout << "사각형 삽입" << endl << endl;
		newShape = new Rect();
		break;
	default:
		cout << "잘못된 값 입력" << endl << endl;
		break;
	}

	if (pStart == NULL) {
		pStart = newShape;
		pLast = newShape;
	}
	else {
		pLast = pLast->add(newShape);
	}
}
void GraphicEditor::deleteShape() {
	int delIndex = UI::delShape();
	
	if (pStart == NULL) {
		cout << "제거할 도형 없음" << endl<<endl;
		return;
	}

	Shape* pre = NULL;
	Shape* cur = pStart;
	if (delIndex == 0) {
		pStart = cur->getNext();
		if (pStart == NULL) {
			pLast = NULL;
		}
		delete cur;
		return;
	}
	
	for (int i = 0; i < delIndex; i++) {
		pre = cur;
		cur = cur->getNext();
		if (cur == NULL) {
			cout << "인덱스 벗어남" << endl<<endl;
			return;
		}
	}
	if (cur->getNext() != NULL) {
		pre->setNext(cur->getNext());
	}
	else {
		pre->setNext(NULL);
		pLast = pre;
	}
	delete cur;
}
void GraphicEditor::showShape() {
	Shape* p = pStart;
	if (pStart == NULL) {
		cout << "출력할 도형 존재하지 않음" << endl << endl;
		return;
	}
	int index = 0;
	while (p != NULL) {
		cout << index << ": ";
		p->paint();
		p = p->getNext();
		index++;
	}
}


//UI 클래스 멤버 구현
int UI::menu() {
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	int choiceMenu;
	cin >> choiceMenu;
	return choiceMenu;
}
int UI::selectShape() {
	cout << "선:1, 원:2, 사각형:3 >> ";
	int choiceShape;
	cin >> choiceShape;
	return choiceShape;
}
int UI::delShape() {
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	int delIndex;
	cin >> delIndex;
	return delIndex;
}