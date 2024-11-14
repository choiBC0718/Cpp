#include <iostream>
#include "GraphicEditor.h"
using namespace std;

//Shape Ŭ���� ��� ����
void Shape::paint() {
	draw();
}
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}

//�� draw�Լ� ����
void Line::draw() {
	cout << "Line" << endl;
}
void Circle::draw() {
	cout << "Circle" << endl;
}
void Rect::draw() {
	cout << "Rectangle" << endl;
}

//GraphicEditor Ŭ���� ��� ����
GraphicEditor::GraphicEditor() {
	pStart = NULL;
	pLast = NULL;
	cout << "�׷��� �������Դϴ�." << endl;
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
		cout << "�� ����" << endl << endl;
		newShape = new Line();
		break;
	case 2:
		cout << "�� ����" << endl << endl;
		newShape = new Circle();
		break;
	case 3:
		cout << "�簢�� ����" << endl << endl;
		newShape = new Rect();
		break;
	default:
		cout << "�߸��� �� �Է�" << endl << endl;
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
		cout << "������ ���� ����" << endl<<endl;
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
			cout << "�ε��� ���" << endl<<endl;
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
		cout << "����� ���� �������� ����" << endl << endl;
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


//UI Ŭ���� ��� ����
int UI::menu() {
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	int choiceMenu;
	cin >> choiceMenu;
	return choiceMenu;
}
int UI::selectShape() {
	cout << "��:1, ��:2, �簢��:3 >> ";
	int choiceShape;
	cin >> choiceShape;
	return choiceShape;
}
int UI::delShape() {
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	int delIndex;
	cin >> delIndex;
	return delIndex;
}