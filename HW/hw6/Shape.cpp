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
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> menuChoice;
	return menuChoice;
}
int UI::selectShape() {
	int shapeChoice;
	cout << "선:1, 원:2, 사각형:3 >> ";
	cin >> shapeChoice;
	return shapeChoice;
}
int UI::delShape() {
	int deleteChoice;
	cout << "삭제하고자 하는 도형의 인덱스 >> ";
	cin >> deleteChoice;
	return deleteChoice;
}