#pragma once
#include <iostream>
using namespace std;

class Dept {
	int size;				//scores배열 크기
	int* scores;			//동적 할당 받을 정수 배열의 주소
public:
	Dept(int size);
	Dept(const Dept& dept);
	~Dept();
	int getSize();
	void read();			 //size만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index);//index의 학생 성적이 60보다 크면 true 리턴
};