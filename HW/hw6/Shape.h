#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};

class Circle :public Shape {
protected:
	virtual void draw();
};
class Rect :public Shape {
protected:
	virtual void draw();
};
class Line :public Shape {
protected:
	virtual void draw();
};

class UI {
public:
	static int menu();
	static int selectShape();
	static int delShape();
};