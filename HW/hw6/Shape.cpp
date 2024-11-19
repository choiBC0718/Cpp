#include <iostream>
#include <vector>
using namespace std;
#include "Shape.h"

void Shape::paint() {
	draw();
}
void Circle::draw() {
	cout << "Circle" << endl;
}
void Rect::draw() {
	cout << "Rectangle" << endl;
}
void Line::draw() {
	cout << "Line" << endl;
}

int UI::menu() {
	int menuChoice;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> menuChoice;
	return menuChoice;
}
int UI::selectShape() {
	int shapeChoice;
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> shapeChoice;
	return shapeChoice;
}
int UI::delShape() {
	int deleteChoice;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> deleteChoice;
	return deleteChoice;
}