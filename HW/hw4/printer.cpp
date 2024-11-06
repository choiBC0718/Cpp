#include <iostream>
#include <string>
#include "printer.h"
using namespace std;

//�θ� Ŭ���� ��� ����
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
	cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,";
}

//��ũ�� �Ļ� Ŭ���� ��� ����
InkjetPrinter::InkjetPrinter(string model, string manufacturer, int printedCount, int availableCount, int availableInk)
	:Printer(model, manufacturer, printedCount, availableCount) {
	this->availableInk = availableInk;
	cout << "��ũ�� : " << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,���� ��ũ "<<availableInk << endl;
}
InkjetPrinter::~InkjetPrinter() {
	cout << endl << "��ũ�� ������ ����" << endl;
}
void InkjetPrinter::printInkjet(int pages) {
	if (this->availableInk < pages && this->availableCount>=pages) {
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (this->availableInk >= pages && this->availableCount < pages) {
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (this->availableInk < pages && this->availableCount < pages) {
		cout << "������ ��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		Printer::print(pages);
		this->availableInk -= pages;
	}
}
void InkjetPrinter::showInkjet() {
	Printer::showState();
	cout << "���� ��ũ " << availableInk << endl;
}

//������ �Ļ� Ŭ���� ��� ����
LaserPrinter::LaserPrinter(string model, string manufacturer, int printedCount, int availableCount, int availableToner)
	: Printer(model, manufacturer, printedCount, availableCount) {
	this->availableToner = availableToner;
	cout << "������ : " << model << " ," << manufacturer << " ,���� ���� " << availableCount << "�� ,���� ���"<<availableToner<<endl;
}
LaserPrinter::~LaserPrinter() {
	cout << "������ ������ ����" << endl;
}
void LaserPrinter::printLaser(int pages) {
	if (this->availableToner < pages && this->availableCount >= pages) {
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (this->availableToner >= pages && this->availableCount < pages) {
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (this->availableToner < pages && this->availableCount < pages) {
		cout << "������ ��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else {
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		Printer::print(pages);
		this->availableToner -= pages;
	}
}
void LaserPrinter::showLaser() {
	Printer::showState();
	cout << "���� ��� " << availableToner << endl;
}