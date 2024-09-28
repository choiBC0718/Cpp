#include <iostream>
using namespace std;
#include "Ram.h"

void Ram::write(int address, char value) {//해당 주소에 문자 입력하는 함수
	mem[address] = value;
}

char Ram::read(int address) { //해당 주소에 저장된 값 읽는 함수
	return mem[address];
}

Ram::Ram() { //생성자를 이용하여 맴버변수 초기화
	for (int i = 0; i < 100 * 1024; i++) { //mem배열 0으로 초기화
		mem[i] = 0;
	}
	size = 100 * 1024;  //size 100*1024로 초기화
}

Ram::~Ram() { //소멸자가 출력하게 될 문자열
	cout << "메모리 제거됨" << endl;
}