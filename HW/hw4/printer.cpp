#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

//부모 클래스 멤버 구현
Printer::Printer(string model, string manufacturer, int printedCount, int availableCount) {
	this->model = model;
	this->manufacturer = manufacturer;
	this->printedCount = printedCount;
	this->availableCount = availableCount;
}
Printer::~Printer() {
	cout << endl;
}
void Printer::print(int pages) {
	this->availableCount -= pages;
}
void Printer::showState() {
	cout << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ,";
}

//잉크젯 파생 클래서 멤버 구현
InkjetPrinter::InkjetPrinter(string model, string manufacturer, int printedCount, int availableCount, int availableInk)
	:Printer(model, manufacturer, printedCount, availableCount) {
	this->availableInk = availableInk;
	cout << "잉크젯 : " << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ,남은 잉크 "<<availableInk << endl;
}
InkjetPrinter::~InkjetPrinter() {
	cout << endl << "잉크젯 프린터 종료" << endl;
}
void InkjetPrinter::printInkjet(int pages) {
	if (this->availableInk < pages && this->availableCount>=pages) {
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (this->availableInk >= pages && this->availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (this->availableInk < pages && this->availableCount < pages) {
		cout << "용지와 잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
	else {
		cout << "프린트하였습니다." << endl;
		Printer::print(pages);
		this->availableInk -= pages;
	}
}
void InkjetPrinter::showInkjet() {
	Printer::showState();
	cout << "남은 잉크 " << availableInk << endl;
}

//레이저 파생 클래스 멤버 구현
LaserPrinter::LaserPrinter(string model, string manufacturer, int printedCount, int availableCount, int availableToner)
	: Printer(model, manufacturer, printedCount, availableCount) {
	this->availableToner = availableToner;
	cout << "레이저 : " << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장 ,남은 토너"<<availableToner<<endl;
}
LaserPrinter::~LaserPrinter() {
	cout << "레이저 프린터 종료" << endl;
}
void LaserPrinter::printLaser(int pages) {
	if (this->availableToner < pages && this->availableCount >= pages) {
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (this->availableToner >= pages && this->availableCount < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (this->availableToner < pages && this->availableCount < pages) {
		cout << "용지와 토너가 부족하여 프린트할 수 없습니다." << endl;
	}
	else {
		cout << "프린트하였습니다." << endl;
		Printer::print(pages);
		this->availableToner -= pages;
	}
}
void LaserPrinter::showLaser() {
	Printer::showState();
	cout << "남은 토너 " << availableToner << endl;
}