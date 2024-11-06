#pragma once
#include <string>
#include <iostream>
using namespace std;

class Printer {
protected:
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	Printer(string model, string manufacturer, int printedCount, int availableCount);
	~Printer();

	void print(int pages);
	void showState();
};


class InkjetPrinter :public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string manufacturer, int printedCount, int availableCount,int availableInk);
	~InkjetPrinter();

	void printInkjet(int pages);
	void showInkjet();
};


class LaserPrinter :public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int printedCount, int availableCount,int availableToner);
	~LaserPrinter();

	void printLaser(int pages);
	void showLaser();
};