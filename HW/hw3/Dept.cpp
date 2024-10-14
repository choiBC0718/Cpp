#include <iostream>
using namespace std;
#include "Dept.h"

Dept::Dept(int size) {		//size를 매개변수로 받는 생성자
	this->size = size;
	scores = new int[size];
}

Dept::Dept(const Dept& dept) {	//복사 생성자
	this->size = dept.size;
	scores = new int[dept.size];//얕은 복사를 하지 않기 위한 메모리 공간 확보
	for (int i = 0; i < dept.size; i++) { //할당한 메모리에 값 복사하여 넣기
		scores[i] = dept.scores[i];
	}
}

Dept::~Dept() {	//소멸자
	if (scores) {
		delete[] scores;		//동적으로 할당 받은 메모리 반환
	}
}

int Dept::getSize() {
	return size;
}

void Dept::read() {				//입력한 점수를 scores 배열에 반복문을 통해 저장
	cout << size << "개 점수 입력>> " ;
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {  //복사 생성자를 통해 생성된 객체의 scores 배열의 값을 지정해줘야 함. 그 방법이 뭐지
	if (scores[index] >= 60) {
		return true;
	}
	else
		return false;
}