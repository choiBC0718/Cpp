#pragma once
#include <iostream>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {};
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
	void setNext(Shape* nextShape) { next = nextShape; }
};

class Line :public Shape {
protected:
	virtual void draw();
public:
	~Line() {
		cout << "Line delete" << endl;
	}
};
class Circle :public Shape {
protected:
	virtual void draw();
	~Circle() {
		cout << "Circle delete" << endl;
	}
};
class Rect :public Shape {
protected:
	virtual void draw();
	~Rect() {
		cout << "Rect delete" << endl;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor();
	~GraphicEditor();
	void insertShape();
	void deleteShape();
	void showShape();
};

class UI {
public:
	static int menu();
	static int selectShape();
	static int delShape();
};